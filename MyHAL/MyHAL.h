/*
 * MyHAL.h
 *
 * Created: 2017.11.05. 12:44:35
 *  Author: Tamás
 */ 


#ifndef MYHAL_H_
#define MYHAL_H_

#include "can.h"

void MyCAN_init(void);
int MyCAN_send_data(/*uint32_t*/uint8_t* data, uint8_t DLC, uint32_t ident);
//void MyCAN_Tx_callback(U8 event);
void MyCAN_Rx_callback(uint8_t* data, U8 event);
uint8_t  MyCAN_Rx_getlength(void);
uint32_t  MyCAN_Rx_getid(void);
//void MyCAN_Canopen_callback_init(void (*IT_callback_func) (uint8_t, uint8_t));
void MyCAN_timer_int_func_init(void (*func) (void));
void MyCAN_int_init(void);





#endif /* MYHAL_H_ */