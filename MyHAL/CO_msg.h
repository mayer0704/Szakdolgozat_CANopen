/*
 * CO_msg.h
 *
 * Created: 2017.11.10. 16:25:41
 *  Author: mayer tamas
 */ 


#ifndef CO_MSG_H_
#define CO_MSG_H_

#include "CO_driver.h"

CO_CANrxMsg_t CO_rxmsg = {
     0,//ident
	 0,//DLC
	 {0,0,0,0,0,0,0,0} //data	 
};







#endif /* CO_MSG_H_ */