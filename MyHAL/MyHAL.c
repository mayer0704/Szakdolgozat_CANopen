

#include "asf.h"
#include "compiler.h"
#include "board.h"
#include "gpio.h"
#include "scif_uc3c.h"
#include "intc.h"

#include "canif.h"
#include "can_msg.h"
#include "MyHAL.h"
#include "CANopen.h"

#define AVR32_GENERAL_UNLOCK      0xaa000000
#define AVR32_CPUDIV_ENABLE       0b10000000
#define CAN_CHANNEL_0             0
#define TIMER_CHANNEL_0             0
#define RX_BUFFER_LENGHT          8
#define TX_BUFFER_LENGHT		  20
/* Local allocation for MOB buffer in HSB_RAM */
#if defined (__GNUC__) && defined (__AVR32__)
volatile can_msg_t mob_ram_ch0[NB_MOB_CHANNEL] __attribute__ ((section (".hsb_ram_loc")));
#elif defined (__ICCAVR32__)
volatile __no_init can_msg_t mob_ram_ch0[NB_MOB_CHANNEL] @0xA0000000;
#endif
typedef enum event_type {Tx,Rx,RRx} event_type;
/** Local function to prepare RX and TX buffers */ 
void can_example_prepare_data(event_type CAN_event);

//struct{
	//Byte id;
	//uint32_t d1;
	//uint32_t d2;
//};

volatile avr32_tc_t *tc = &AVR32_TC0;//timer struktúra

typedef union convert_bytearray_to_64bit //8*8 bites adattömböt konvertál 64 bites változóvá
{
	Byte byte_array[8];
	U64 Txdata;
}converter_bytearray_to_64bit;

typedef union convert_32_to_8
{
	uint32_t num32;//32 bitre 8 bitenként hivatkozhatunk, ha csak valamely 8 bitre van szükségünk

	struct
	{
		uint8_t a;
		uint8_t b;
		uint8_t c;
		uint8_t d;

	} bytes;

}converter_32_to_8;



bool MyCAN_event_occured=false;
uint8_t MyCAN_event_handle;
uint8_t MyCAN_event;

bool Timer_event_occured=false;
//indicate CAN recieption
bool can_recieved=false;

uint16_t interrupt_counter_2=0;
//test variable
uint8_t Rx_Buffer[RX_BUFFER_LENGHT];

uint8_t Tx_Buffer[TX_BUFFER_LENGHT]=
{
   0x11,
   0x12,
   0x13,
   0x14,
   0x15,
   0x16,
   0x17,
   0x18,
   0x21,
   0x22,
   0x23,
   0x24,
   0x25,
   0x26,
   0x27,
   0x28,
   0x31,
   0x32,
   0x33,
   0x34,
};




void my_clk_init(void);

void enable_CAN_Int(void);

/** Define the number of message received on CAN Channel 0 */
volatile U8 nb_message_received_on_channel0 = 0;
/** Call Back prototype */
void MyCAN_int_callback(U8 handle, U8 event);
/** Call Back called by can_drv */


int MyCAN_receive_data(uint8_t* data, Byte length);

void MyCAN_loop(void);
void MyCAN_gclk_init(void);
void MyCAN_int_init(void);
void MyCAN_pin_init(void);


static void tc_irq(void);
void MyCAN_Timer_init(void);

uint8_t Wait_For_It=1;//segéd változó, a következõ küldés csak akkor indul ha az elõzõ által kiváltott interrupt nullába tette ezt a változót
uint8_t it_counter=0;

bool button_is_pushed=false;//teszteléshez

void  (*MyCAN_CANopen_Interrupt_function) (uint8_t, uint8_t)=NULL;//A FELSÕBB RÉTEG BELI INTERRUPT FÜGGVÉNYRE MUTATÓ POINTER
void (*MyCAN_timer_int_func) (void)=NULL;//pdo thread re mutató pointer





//gomb nyomásra interrupt
#if (defined __GNUC__)
__attribute__((__interrupt__))
#elif (defined __ICCAVR32__)
__interrupt
#endif
static void gpio_int_handler(void)
{
 button_is_pushed=true;
 gpio_clear_pin_interrupt_flag(AVR32_PIN_PB24);
}


//fogadásra interrupt
//void MyCAN_Canopen_callback_init(void (*IT_callback_func) (uint8_t, uint8_t))
//{
	//MyCAN_CANopen_Interrupt_function=IT_callback_func;
//}

//timer interrupt által lefutatott függvény
void MyCAN_timer_int_func_init(void (*func) (void))
{
	MyCAN_timer_int_func=func;
}

#if defined (__GNUC__)
__attribute__((__interrupt__))
#elif defined (__ICCAVR32__)
__interrupt
#endif


//timer interrupt, PDO szálat minden 1ms-ban le kell futattni
static void tc_irq(void)
{
	// Increment the ms seconds counter
	uint32_t b;

	// Clear the interrupt flag. This is a side effect of reading the TC SR.
	tc_read_sr(&AVR32_TC0, 0);
	Timer_event_occured=true;
	//MyCAN_timer_int_func();

	gpio_toggle_pin(AVR32_PIN_PB08);
}



//a CANopen_driver hívja meg miután felsõbb szinten le lett kezelve az interrupt
//void MyCAN_Tx_callback(U8 event)
//{
	//appli_tx_msg.status = event;
	//Wait_For_It=0;
//}

//a CANopen_driver hívja meg miután felsõbb szinten le lett kezelve az interrupt
void MyCAN_Rx_callback(uint8_t* data, U8 event)
{
	
	MyCAN_receive_data(Rx_Buffer,RX_BUFFER_LENGHT);
	
	for (int i=0;i<appli_rx_msg.dlc;i++)
	{
		data[i]=Rx_Buffer[i];
	}
	//ide forciklus kell 
	appli_rx_msg.status = event;
}
uint8_t  MyCAN_Rx_getlength(void)
{
	return appli_rx_msg.dlc;
}
uint32_t MyCAN_Rx_getid(void)
{
	return appli_rx_msg.can_msg->id;
}

void MyCAN_int_callback(U8 handle, U8 event)//ide érkezik meg az interrupt
{
	interrupt_counter_2++;
	MyCAN_event_occured=true;
	MyCAN_event_handle=handle;
	MyCAN_event=event;
	if (handle==appli_tx_msg.handle)
	{
		appli_tx_msg.status = event;
		Wait_For_It=0;
		return;
	}
	if (handle==appli_rx_msg.handle)
	{
		can_recieved=true;
		gpio_set_pin_low(AVR32_PIN_PB08);
		return;
	}
}

void MyCAN_Timer_init()
{


	
	// Options for waveform generation.
	// Options for waveform generation.
	static const tc_waveform_opt_t waveform_opt = {
		// Channel selection.
		.channel  = 0,
		// Software trigger effect on TIOB.
		.bswtrg   = TC_EVT_EFFECT_NOOP,
		// External event effect on TIOB.
		.beevt    = TC_EVT_EFFECT_NOOP,
		// RC compare effect on TIOB.
		.bcpc     = TC_EVT_EFFECT_NOOP,
		// RB compare effect on TIOB.
		.bcpb     = TC_EVT_EFFECT_NOOP,
		// Software trigger effect on TIOA.
		.aswtrg   = TC_EVT_EFFECT_NOOP,
		// External event effect on TIOA.
		.aeevt    = TC_EVT_EFFECT_NOOP,
		// RC compare effect on TIOA.
		.acpc     = TC_EVT_EFFECT_NOOP,
		/*
		 * RA compare effect on TIOA.
		 * (other possibilities are none, set and clear).
		 */
		.acpa     = TC_EVT_EFFECT_NOOP,
		/*
		 * Waveform selection: Up mode with automatic trigger(reset)
		 * on RC compare.
		 */

		.wavsel   = TC_WAVEFORM_SEL_UP_MODE_RC_TRIGGER,
		// External event trigger enable.
		.enetrg   = false,
		// External event selection.
		.eevt     = 0,
		// External event edge selection.
		.eevtedg  = TC_SEL_NO_EDGE,
		// Counter disable when RC compare.
		.cpcdis   = false,
		// Counter clock stopped with RC compare.
		.cpcstop  = false,
		// Burst signal selection.
		.burst    = false,
		// Clock inversion.
		.clki     = false,
		// Internal source clock 3, connected to fPBC / 128.
		.tcclks   = TC_CLOCK_SOURCE_TC5
	};

	
	static const tc_interrupt_t tc_interrupt = {
		.etrgs = 0,
		.ldrbs = 0,
		.ldras = 0,
		.cpcs  = 1, 
		.cpbs  = 0,
		.cpas  = 0,
		.lovrs = 0,
		.covfs = 0
	};
	
	tc_init_waveform(tc, &waveform_opt);//tc = &AVR32_TC0


	tc_write_rc(tc, TIMER_CHANNEL_0, (1000/8));//beleirom hogy meddig számoljon

	tc_configure_interrupts(tc, TIMER_CHANNEL_0, &tc_interrupt);
	
	tc_start(tc, TIMER_CHANNEL_0);
}

void enable_CAN_Int()
{
	//Writing a bit to one will enable the corresponding MOb
	CANIF_mob_enable(CAN_CHANNEL_0,appli_rx_msg.handle);
	//Writing a bit to one will set the corresponding bit in MOBIMR
	//-> enebale interrupt to the corresponding Mob
	CANIF_mob_enable_interrupt(CAN_CHANNEL_0,appli_rx_msg.handle);
}

/** Prepare Data on CAN Bus. */


void my_clk_init()
{
	irqflags_t flags;
	flags = cpu_irq_save();
	//Write this bit field to AVR32_GENERAL_UNLOCK to enable unlock.
	//Bitwise OR the address of the specific register to unlock to this bit field.
	AVR32_PM.unlock = AVR32_GENERAL_UNLOCK | AVR32_PM_CPUSEL;
	
	//Commneted , because of NO division
		//uint32_t cpu_cksel=4
		//AVR32_PM.cpusel = AVR32_CPUDIV_ENABLE | cpu_cksel; devided by 2^(1+cpu_cksel) 

	AVR32_SCIF.unlock = AVR32_GENERAL_UNLOCK | AVR32_SCIF_OSCCTRL;


	//osc0 CONTROLLWORD setup:
		//startup time
		//oscillator gain
		//oscillator mode 
		//--> datasheet p.104
	AVR32_SCIF.oscctrl[0] =
	(AVR32_SCIF_OSCCTRL0_STARTUP_0_RCOSC << AVR32_SCIF_OSCCTRL_STARTUP)
	| (AVR32_SCIF_OSCCTRL0_GAIN_G3 << AVR32_SCIF_OSCCTRL_GAIN)
	| (AVR32_SCIF_OSCCTRL_MODE_CRYSTAL << AVR32_SCIF_OSCCTRL_MODE)
	| (1U << AVR32_SCIF_OSCCTRL_OSCEN);//enable osscillator

	//wait for startup
	while(!(!!(AVR32_SCIF.pclksr & (1 << AVR32_SCIF_OSC0RDY))))
	{
	}
	
	AVR32_PM.unlock = AVR32_GENERAL_UNLOCK | AVR32_PM_MCCTRL;
	//choosing oscillator source
	AVR32_PM.mcctrl = SYSCLK_SRC_OSC0;
}
//////////////////////////////////////////////////////////////////////////
// 


/// Sikeres küldés return 0
// Hiba esetén hibakód
// data= struct-> elsõ 8 byteban van az adat
// length= hossz
// byte tömb
int MyCAN_send_data(/*uint32_t*/uint8_t* data, uint8_t DLC, uint32_t ident)
{
	appli_tx_msg.can_msg->data.u64=0;
	appli_tx_msg.can_msg->id=ident;
	uint8_t rem_length =DLC;
	uint8_t can_msg_length;
	//converter_32_to_8 temp;
	converter_bytearray_to_64bit Tx_temp;
	volatile uint32_t b=0;


	while(rem_length>0)
	{
		Wait_For_It=1;
		can_msg_length=(rem_length>=8) ? 8 : rem_length;

		for(uint8_t i=0; i<can_msg_length;i++)
		{
			uint8_t no_of_element = DLC-rem_length;
			//temp.num32=data[no_of_element];
			//Tx_temp.byte_array[i] = temp.bytes.a;
			Tx_temp.byte_array[i]=data[no_of_element];
			rem_length--;
		}
		//appli_tx_msg.handle==CAN_CMD_REFUSED lekezelni
		appli_tx_msg.dlc=can_msg_length;
		appli_tx_msg.can_msg->data.u64=Tx_temp.Txdata;
		can_tx(0, appli_tx_msg.handle, appli_tx_msg.dlc, appli_tx_msg.req_type,appli_tx_msg.can_msg);

		
		while (Wait_For_It)
		{
			b++;
		}

	}

	return b;
}


//CANIF_mob_clr_dlc(0,0);
//CANIF_mob_set_dlc(0,0,length_8_mod);
//CANIF_set_data(0,0,appli_tx_msg.can_msg->data.u64);
//CANIF_config_tx(0,0);
//CANIF_clr_interrupt_status(0);
//CANIF_mob_clear_txok_status(0,0);
//CANIF_mob_enable(0,0);
//CANIF_mob_enable_interrupt(0,0);

// return hossz
// buffer out, ide jön amit küldtél, byte tömb
// hossz, amit várunk vagy 0 fogadás
// 
int MyCAN_receive_data(uint8_t* data, Byte length)
{
    converter_bytearray_to_64bit Rx_temp;
	
	//converter_32_to_8 temp;
	//temp.num32 = 0; 
	int iter;
	U8 num_of_rxbyte;
	
	//ha küldök üzenetet akkor már itt bennvan az ID az IDmezõben
	Rx_temp.Txdata=appli_rx_msg.can_msg->data.u64;
	

	appli_rx_msg.can_msg->data.u64 = can_get_mob_data(CAN_CHANNEL_0,appli_rx_msg.handle).u64;
	appli_rx_msg.can_msg->id = can_get_mob_id(CAN_CHANNEL_0,appli_rx_msg.handle);
	appli_rx_msg.dlc = can_get_mob_dlc(CAN_CHANNEL_0,appli_rx_msg.handle);
	//azért van elõbb az adat és ID átadás mert a can_rx függvény a már meglévõ default ID-t állítja be az appli_rx_msg-ben 
	can_rx(CAN_CHANNEL_0, appli_rx_msg.handle, appli_rx_msg.req_type,
	appli_rx_msg.can_msg);

	Rx_temp.Txdata= appli_rx_msg.can_msg->data.u64;
	
	num_of_rxbyte=appli_rx_msg.dlc;

	for(iter=0;iter<length;iter++)
	{
	//temp.bytes.a=Rx_temp.byte_array[i];
	//data[i]=temp.num32;
	
		if (iter<num_of_rxbyte)
		{
			data[iter]=Rx_temp.byte_array[iter];
		}
		else
		{
			data[iter]=0;
		}
	}


	////
	////ITT KINULLÁZOM A MARADÉKOT
	////
	return 0;
	
}

void MyCAN_gclk_init()
{
	/* Setup the generic clock for CAN */
	/*Generic Clock Control Register*/
	scif_gc_setup(AVR32_SCIF_GCLK_CANIF,//id of proper gclk(gclk array)
				SCIF_GCCTRL_OSC0,//source of clk(OSCEL field)
				AVR32_SCIF_GC_NO_DIV_CLOCK,//division enable(DIVEN field)
				0);//division factor is zero(DIV field)

	/* Now enable the generic clock */
	/*CEN field*/
	scif_gc_enable(AVR32_SCIF_GCLK_CANIF);
}

void MyCAN_pin_init()
{
	static const gpio_map_t CAN_GPIO_MAP = {
		{AVR32_CANIF_RXLINE_0_0_PIN, AVR32_CANIF_RXLINE_0_0_FUNCTION},
		{AVR32_CANIF_TXLINE_0_0_PIN, AVR32_CANIF_TXLINE_0_0_FUNCTION}
	};
	/* Assign GPIO to CAN. */
	gpio_enable_module(CAN_GPIO_MAP,
		sizeof(CAN_GPIO_MAP) / sizeof(CAN_GPIO_MAP[0]));
}

void MyCAN_int_init()
{
	/* Disable all interrupts. */
	

	/* Initialize interrupt vectors. */
	INTC_init_interrupts();
	INTC_register_interrupt(&gpio_int_handler, AVR32_GPIO_IRQ_0+AVR32_PIN_PB24/8, AVR32_INTC_INT1);
	gpio_enable_pin_interrupt(AVR32_PIN_PB24,GPIO_RISING_EDGE);

		
	INTC_register_interrupt(&tc_irq, AVR32_TC0_IRQ0, AVR32_INTC_INT1);
		
	
	

	/* Initialize channel 0 */
	can_init(CAN_CHANNEL_0, ((uint32_t)&mob_ram_ch0[0]), CANIF_CHANNEL_MODE_NORMAL,
			MyCAN_int_callback);


	appli_tx_msg.handle = can_mob_alloc(CAN_CHANNEL_0);
	appli_rx_msg.handle = can_mob_alloc(CAN_CHANNEL_0);
	appli_remote_rx_msg.handle = can_mob_alloc(CAN_CHANNEL_0);
	appli_tx_msg.status=CAN_STATUS_COMPLETED;
	appli_rx_msg.status=CAN_STATUS_COMPLETED;
	appli_remote_rx_msg.status=CAN_STATUS_COMPLETED;
	
	/* Enable all interrupts. */
	
}

void MyCAN_init()
{
	/* Initialize the system clocks */
	//sysclk_init();
	my_clk_init();

	MyCAN_gclk_init();
	

	MyCAN_pin_init();
	
	//Button
	gpio_configure_pin(AVR32_PIN_PB24, GPIO_DIR_INPUT);
	//gpio_enable_pin_glitch_filter(AVR32_PIN_PB24);

	//Led
	gpio_configure_pin(AVR32_PIN_PB08, GPIO_DIR_OUTPUT | GPIO_INIT_HIGH);

	MyCAN_int_init();
	
	/*Enable Tx and Rx interrupt for CAN*/
	enable_CAN_Int();

	MyCAN_Timer_init();

}

void MyCAN_loop(void)
{
	MyCAN_init();
	
	
	
   
	
	volatile uint8_t abc=0;

while(1) {
	     /*auxiliary variable for led blink when CAN Rx occurs*/
		 

	     //interrupttal
		
		 if(button_is_pushed)
		 {
            /*Send CAN message*/
			//MyCAN_send_data(Tx_Buffer,TX_BUFFER_LENGHT);
			button_is_pushed=false;
			//can_example_prepare_data(0);
			
		 }
		 abc=it_counter;
		

		

		//can_recieved másra használom
		 //if(can_recieved)
		 //{
	 		//iter++;
			//
			//if(iter==1000)
			//{
				//gpio_set_pin_high(AVR32_PIN_PB08);
				//can_recieved=false;
				//iter=0;
			//}
		 //}

		 }
		 
}
