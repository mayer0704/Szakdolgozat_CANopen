

#include "asf.h"
#include "compiler.h"
#include "board.h"
//#include "power_clocks_lib.h"
#include "gpio.h"
//#include "pm_uc3c.h"
#include "scif_uc3c.h"
#include "intc.h"
#include "can.h"
#include "canif.h"
//#include "usart.h"
//#include "print_funcs.h"
#include "can_conf.h"

#define AVR32_GENERAL_UNLOCK      0xaa000000
#define AVR32_CPUDIV_ENABLE       0b10000000
#define CAN_CHANNEL_0             0
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



typedef union convert_bytearray_to_64bit
{
	Byte byte_array[8];
	U64 Txdata;
}converter_bytearray_to_64bit;

typedef union convert_32_to_8
{
	uint32_t num32;

	struct
	{
		uint8_t a;
		uint8_t b;
		uint8_t c;
		uint8_t d;

	} bytes;

}converter_32_to_8;

//indicate CAN recieption
bool can_recieved=false;
//test variable
uint32_t Rx_Buffer[RX_BUFFER_LENGHT];

uint32_t Tx_Buffer[TX_BUFFER_LENGHT]=
{
   0x11000000,
   0x12000000,
   0x13000000,
   0x14000000,
   0x15000000,
   0x16000000,
   0x17000000,
   0x18000000,
   0x21000000,
   0x22000000,
   0x23000000,
   0x24000000,
   0x25000000,
   0x26000000,
   0x27000000,
   0x28000000,
   0x31000000,
   0x32000000,
   0x33000000,
   0x34000000, 
};




void my_clk_init(void);

void enable_CAN_Int(void);

/** Define the number of message received on CAN Channel 0 */
volatile U8 nb_message_received_on_channel0 = 0;
/** Call Back prototype */
void can_out_callback_channel0(U8 handle, U8 event);
/** Call Back called by can_drv */

int can_send_data(uint32_t* data, Byte length);
int can_receive_data(uint32_t* data, Byte length);
void Init(void);
uint8_t Wait_For_It=1;
uint8_t it_counter=0;

bool button_is_pushed=false;





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




void can_out_callback_channel0(U8 handle, U8 event)
{
	switch(handle)
	{
	case Tx:
		{
		appli_tx_msg.status = event;
		Wait_For_It=0;
		it_counter++;
		CANIF_mob_clear_txok_status(1,handle);
		CANIF_mob_clear_status(1,handle)
		break;
		}
	case Rx:
		{
		can_recieved=true;
		gpio_set_pin_low(AVR32_PIN_PB08);
		//can_example_prepare_data(Rx);
		//appli_rx_msg.can_msg->data.u64 = can_get_mob_data(CAN_CHANNEL_0,handle).u64;
		//appli_rx_msg.can_msg->id = can_get_mob_id(CAN_CHANNEL_0,handle);
		//appli_rx_msg.dlc = can_get_mob_dlc(CAN_CHANNEL_0,handle);
		//
		
		can_receive_data(Rx_Buffer,RX_BUFFER_LENGHT);
		appli_rx_msg.status = event;
		break;
		}
	case RRx:
		{
		break;
		}
	default:
		{
		switch(event)
		{
			case CAN_STATUS_WAKEUP:
			{
				break;
			}
			case CAN_STATUS_BUSOFF:
			{
				break;
			}
			case CAN_STATUS_ERROR:
			{
				break;
			}
		}
		break;
		} 
	}
	//enable_CAN_Int();mtxiscr,caniscr
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
void can_example_prepare_data(event_type CAN_event)
{
	/* Prepare Transmission Mode */
	if (CAN_event == Tx) {
		/* Check return if no mob are available */
		if (appli_tx_msg.handle==CAN_CMD_REFUSED) {
			while(1);
		}
		can_tx(0, appli_tx_msg.handle, appli_tx_msg.dlc, appli_tx_msg.req_type,
			appli_tx_msg.can_msg);
			//increment transmitted data--> test
			appli_tx_msg.can_msg->data.u64++;
	}
	/* Prepare Reception Mode */
	else if (CAN_event == Rx) {
	/*with this function we will initialize the can id and can id_mask furthermore*/
		can_rx(CAN_CHANNEL_0, appli_rx_msg.handle, appli_rx_msg.req_type, 
			appli_rx_msg.can_msg);
		
	}
	/* Prepare Remote Reception Mode */
	else if (CAN_event == RRx) {


		can_rx(CAN_CHANNEL_0, appli_remote_rx_msg.handle, appli_remote_rx_msg.req_type,
			appli_remote_rx_msg.can_msg);
	}
}

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
int can_send_data(uint32_t* data, Byte length)
{
	appli_tx_msg.can_msg->data.u64=0;

	uint8_t rem_length =length;
	uint8_t can_msg_length;
	converter_32_to_8 temp;
	converter_bytearray_to_64bit Tx_temp;
	volatile int b=0;


	while(rem_length>0)
	{
		Wait_For_It=1;
		can_msg_length=(rem_length>=8) ? 8 : rem_length;

		for(uint8_t i=0; i<can_msg_length;i++)
		{
			uint8_t no_of_element = length-rem_length;
			temp.num32=data[no_of_element];
			Tx_temp.byte_array[i] = temp.bytes.a;
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
int can_receive_data(uint32_t* buffer, Byte length)
{
    converter_bytearray_to_64bit Rx_temp;
	converter_32_to_8 temp;
	uint32_t ajdi;
	temp.num32 = 0;
	U8 num_of_rxbyte;
	can_rx(CAN_CHANNEL_0, appli_rx_msg.handle, appli_rx_msg.req_type, 
				appli_rx_msg.can_msg);

	Rx_temp.Txdata= appli_rx_msg.can_msg->data.u64;
	appli_rx_msg.can_msg->data.u64 = can_get_mob_data(CAN_CHANNEL_0,appli_rx_msg.handle).u64;
	appli_rx_msg.can_msg->id = can_get_mob_id(CAN_CHANNEL_0,appli_rx_msg.handle);
	appli_rx_msg.dlc = can_get_mob_dlc(CAN_CHANNEL_0,appli_rx_msg.handle);
	
	Rx_temp.Txdata= appli_rx_msg.can_msg->data.u64;
	num_of_rxbyte=appli_rx_msg.dlc;

	for(int i=0;(i<length)&&(i<num_of_rxbyte);i++)
	{
	temp.bytes.a=Rx_temp.byte_array[i];
	buffer[i]=temp.num32;
	}
	return 0;
	
}

void Init()
{
	/* Initialize the system clocks */
	//sysclk_init();
	my_clk_init();

	/* Setup the generic clock for CAN */
	/*Generic Clock Control Register*/
	scif_gc_setup(AVR32_SCIF_GCLK_CANIF,//id of proper gclk(gclk array)
				SCIF_GCCTRL_OSC0,//source of clk(OSCEL field)
				AVR32_SCIF_GC_NO_DIV_CLOCK,//division enable(DIVEN field)
				0);//division factor is zero(DIV field)

	/* Now enable the generic clock */
	/*CEN field*/
	scif_gc_enable(AVR32_SCIF_GCLK_CANIF);

	static const gpio_map_t CAN_GPIO_MAP = {
		{AVR32_CANIF_RXLINE_0_0_PIN, AVR32_CANIF_RXLINE_0_0_FUNCTION},
		{AVR32_CANIF_TXLINE_0_0_PIN, AVR32_CANIF_TXLINE_0_0_FUNCTION}
	};
	/* Assign GPIO to CAN. */
	gpio_enable_module(CAN_GPIO_MAP,
		sizeof(CAN_GPIO_MAP) / sizeof(CAN_GPIO_MAP[0]));
	//Button
	gpio_configure_pin(AVR32_PIN_PB24, GPIO_DIR_INPUT);
	//gpio_enable_pin_glitch_filter(AVR32_PIN_PB24);

	//Led
	gpio_configure_pin(AVR32_PIN_PB08, GPIO_DIR_OUTPUT | GPIO_INIT_HIGH);

	/* Disable all interrupts. */
	Disable_global_interrupt();

	/* Initialize interrupt vectors. */
	INTC_init_interrupts();
	INTC_register_interrupt(&gpio_int_handler, AVR32_GPIO_IRQ_0+AVR32_PIN_PB24/8, AVR32_INTC_INT1);
	gpio_enable_pin_interrupt(AVR32_PIN_PB24,GPIO_RISING_EDGE);

	
	
	

	/* Initialize channel 0 */
	can_init(CAN_CHANNEL_0, ((uint32_t)&mob_ram_ch0[0]), CANIF_CHANNEL_MODE_NORMAL,
			can_out_callback_channel0);


	appli_tx_msg.handle = can_mob_alloc(CAN_CHANNEL_0);
	appli_rx_msg.handle = can_mob_alloc(CAN_CHANNEL_0);
	appli_remote_rx_msg.handle = can_mob_alloc(CAN_CHANNEL_0);
	appli_tx_msg.status=CAN_STATUS_COMPLETED;
	appli_rx_msg.status=CAN_STATUS_COMPLETED;
	appli_remote_rx_msg.status=CAN_STATUS_COMPLETED;
	
	/* Enable all interrupts. */
	Enable_global_interrupt();
	/*Enable Tx and Rx interrupt for CAN*/
	enable_CAN_Int();
}

int main(void)
{
	Init();
	
	
	
   
	uint32_t iter=0;
	volatile uint8_t abc=0;

while(1) {
	     /*auxiliary variable for led blink when CAN Rx occurs*/
		 

	     //interrupttal
		
		 if(button_is_pushed)
		 {
            /*Send CAN message*/
			can_send_data(Tx_Buffer,TX_BUFFER_LENGHT);
			button_is_pushed=false;
			//can_example_prepare_data(0);
			
		 }
		 abc=it_counter;
		

		


		 if(can_recieved)
		 {
	 		iter++;
			
			if(iter==1000)
			{
				gpio_set_pin_high(AVR32_PIN_PB08);
				can_recieved=false;
				iter=0;
			}
		 }

		 }
		 
}
