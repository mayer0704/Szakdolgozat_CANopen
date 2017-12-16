/*
 * CANopen main program file.
 *
 * This file is a template for other microcontrollers.
 *
 * @file        main_generic.c
 * @author      Janez Paternoster
 * @copyright   2004 - 2015 Janez Paternoster
 *
 * This file is part of CANopenNode, an opensource CANopen Stack.
 * Project home page is <https://github.com/CANopenNode/CANopenNode>.
 * For more information on CANopen see <http://www.can-cia.org/>.
 *
 * CANopenNode is free and open source software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Following clarification and special exception to the GNU General Public
 * License is included to the distribution terms of CANopenNode:
 *
 * Linking this library statically or dynamically with other modules is
 * making a combined work based on this library. Thus, the terms and
 * conditions of the GNU General Public License cover the whole combination.
 *
 * As a special exception, the copyright holders of this library give
 * you permission to link this library with independent modules to
 * produce an executable, regardless of the license terms of these
 * independent modules, and to copy and distribute the resulting
 * executable under terms of your choice, provided that you also meet,
 * for each linked independent module, the terms and conditions of the
 * license of that module. An independent module is a module which is
 * not derived from or based on this library. If you modify this
 * library, you may extend this exception to your version of the
 * library, but you are not obliged to do so. If you do not wish
 * to do so, delete this exception statement from your version.
 */


#include "CANopen.h"
#include "MyHAL.h"


#define TMR_TASK_INTERVAL   (1000)          /* Interval of tmrTask thread in microseconds */
#define INCREMENT_1MS(var)  (var++)         /* Increment 1ms variable in tmrTask */
#define ERROR_ENTRY_NUMBER  63
#define TEMP_HIGH 99
#define TEMP_LOW  11
#define TEMP_NORMAL  0
#define ERROR_OBJ_ELEMENT_NUM 8
#define TEMP_RECHECK_INTERVAL 1000


/* Global variables and objects */
    volatile uint16_t   CO_timer1ms = 0U;   /* variable increments each millisecond */
	static void tmrTask_thread(void);
	void Temp_simulation_process(void);
	void Errorshift(void);
	void Temp_error_check_process(void);
	extern bool can_recieved;

	extern bool MyCAN_event_occured;
	extern uint8_t MyCAN_event_handle;
	extern uint8_t MyCAN_event;
	extern bool Timer_event_occured;
	extern bool button_is_pushed;

	bool TEMP_increase=true;
	bool TEMP_decrease=false;
	uint16_t TEMP_recheck_counter=0;

/* main ***********************************************************************/
int main (void){
    CO_NMT_reset_cmd_t reset = CO_RESET_NOT;

    /* Configure microcontroller. */


    /* initialize EEPROM */


    /* increase variable each startup. Variable is stored in EEPROM. */
    OD_powerOnCounter++;


    while(reset != CO_RESET_APP){
/* CANopen communication reset - initialize CANopen objects *******************/
        CO_ReturnError_t err;
        uint16_t timer1msPrevious;

        /* disable CAN and CAN interrupts */
		Disable_global_interrupt();
		
        /* initialize CANopen */
        err = CO_init(0/* CAN module address */, 10/* NodeID */, 125 /* bit rate */);
        if(err != CO_ERROR_NO){
            while(1);
            /* CO_errorReport(CO->em, CO_EM_MEMORY_ALLOCATION_ERROR, CO_EMC_SOFTWARE_INTERNAL, err); */
        }


        /* Configure Timer interrupt function for execution every 1 millisecond */
		
		MyCAN_timer_int_func_init(tmrTask_thread);//itt inicializálom timer interruptként a PDO thread-et
		
		/* start CAN */
		CO_CANsetNormalMode(CO->CANmodule[0]);
        /* Configure CAN transmit and receive interrupt */
		//MyCAN_int_init();//legutoljára inicializálom az interruptokat, hogy ne szakítsa meg az inicializálást

		Enable_global_interrupt();
        

        reset = CO_RESET_NOT;
        timer1msPrevious = CO_timer1ms;

		
        while(reset == CO_RESET_NOT){
/* loop for normal program execution ******************************************/
           
		  
		   
		    uint16_t timer1msCopy, timer1msDiff;
			uint8_t test_errorrre1=CO->em->errorStatusBits[0];
			uint8_t test_errorrre2=CO->em->errorStatusBits[1];
			uint8_t test_errorrre3=CO->em->errorStatusBits[2];
			uint8_t test_errorrre4=CO->em->errorStatusBits[3];
			uint8_t test_errorrre5=CO->em->errorStatusBits[4];
			uint8_t test_errorrre6=CO->em->errorStatusBits[5];
            timer1msCopy = CO_timer1ms;
            timer1msDiff = timer1msCopy - timer1msPrevious;
            timer1msPrevious = timer1msCopy;
			
			if (button_is_pushed)
			{
				button_is_pushed=false;
				CO_OD_RAM.Error[0]++;//.Error_sub1++;
			}
            /* CANopen process */
            reset = CO_process(CO, timer1msDiff, NULL);

            /* Nonblocking application code may go here. */
			if (MyCAN_event_occured)
			{
			
			MyCAN_event_occured=false;
			CO_CAN1InterruptHandler(MyCAN_event_handle,MyCAN_event);
			MyCAN_event_occured=false;
			}
			
			if (Timer_event_occured)
			{
			tmrTask_thread();
			}




            /* Process EEPROM */
        }
    }


/* program exit ***************************************************************/
    /* stop threads */


    /* delete objects from memory */
    CO_delete(0/* CAN module address */);


    /* reset */
    return 0;
}


/* timer thread executes in constant intervals ********************************/
static void tmrTask_thread(void){

    

        /* sleep for interval */

        INCREMENT_1MS(CO_timer1ms);

		if (CO->NMT->operatingState==5)
		{
	
			TEMP_recheck_counter++;
	
			if(TEMP_recheck_counter==TEMP_RECHECK_INTERVAL)
			{
			Temp_simulation_process();
			Temp_error_check_process();
			TEMP_recheck_counter=0;
			}
			
		}

        if(CO->CANmodule[0]->CANnormal) {
            bool_t syncWas;

            /* Process Sync and read inputs */
            syncWas = CO_process_SYNC_RPDO(CO, TMR_TASK_INTERVAL);

            /* Further I/O or nonblocking application code may go here. */

            /* Write outputs */
            CO_process_TPDO(CO, syncWas, TMR_TASK_INTERVAL);

            /* verify timer overflow */
            if(0) {
                CO_errorReport(CO->em, CO_EM_ISR_TIMER_OVERFLOW, CO_EMC_SOFTWARE_INTERNAL, 0U);
            }
        }
    
}

void Temp_simulation_process()
{
	if ((TEMP_increase==true)&&(TEMP_decrease==false))
	{
		CO_OD_RAM.Water_Heating.Temperature_act++;
		if (CO_OD_RAM.Water_Heating.Temperature_act==100)
		{
			TEMP_decrease=true;
			TEMP_increase=false;
		}
	}
	if ((TEMP_increase==false)&&(TEMP_decrease==true))
	{
		CO_OD_RAM.Water_Heating.Temperature_act--;
		if (CO_OD_RAM.Water_Heating.Temperature_act==0)
		{
			TEMP_decrease=false;
			TEMP_increase=true;
		}
	}

}

void Temp_error_check_process()
{
	if (CO_OD_RAM.Water_Heating.Temperature_act>90)
	{
	    Errorshift();
	    CO_OD_RAM.Error[0]=TEMP_HIGH;
	}
	
	if (CO_OD_RAM.Water_Heating.Temperature_act<10)
	{
		Errorshift();
		CO_OD_RAM.Error[0]=TEMP_LOW;
	}
	if (CO_OD_RAM.Water_Heating.Temperature_act>10 && CO_OD_RAM.Water_Heating.Temperature_act<90)
	{
		Errorshift();
		CO_OD_RAM.Error[0]=TEMP_NORMAL;
	}
}

void Errorshift()
{
 for (int i=ERROR_OBJ_ELEMENT_NUM-1; i>0 ;i--)
 {
	 CO_OD_RAM.Error[i]=CO_OD_RAM.Error[i-1];
 }
}