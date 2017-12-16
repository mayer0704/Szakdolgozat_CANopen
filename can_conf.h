/*
 * can_conf.h
 *
 * Created: 2017.10.18. 13:39:07
 *  Author: mayer tamas
 */ 


#ifndef CAN_CONF_H_
#define CAN_CONF_H_






//_____ I N C L U D E S ________________________________________________________
#include "avr32/io.h"
#include "compiler.h"
#include "can.h"
#include "board.h"

/*
 *
 */

/*
 * Mail Box Definition
 */
// -----------------------------------------------------------------
// CAN Message Definition: Tx Message
#if defined (__ICCAVR32__)
can_msg_t msg_tx_sot = {
  0x130,                    // Identifier
  0x1ff,                    // Mask
  0x0102030405060708LL,     // Data
};
#else
can_msg_t msg_tx_sot = {
  {
    {
      .id = 0x130,                    // Identifier
      .id_mask  = 0x1ff,              // Mask
    },
  },
 .data.u64 = 0x0000000000000000LL,    // Data
};
#endif

// MOB Message Definition: Tx Message
can_mob_t appli_tx_msg = {
  CAN_MOB_NOT_ALLOCATED,            // Handle: by default CAN_MOB_NOT_ALLOCATED
  &msg_tx_sot,                      // Pointer on CAN Message
  8,                                // Data length DLC
  CAN_DATA_FRAME,                   // Request type : CAN_DATA_FRAME or CAN_REMOTE_FRAME
  CAN_STATUS_NOT_COMPLETED          // Status: by default CAN_STATUS_NOT_COMPLETED
};

// -----------------------------------------------------------------
// CAN Message Definition: Rx Message
#if defined (__ICCAVR32__)
can_msg_t msg_rx_listening = {
  0,                // Identifier
  0,                // Mask
  0x0LL,            // Data
};
#else
can_msg_t msg_rx_listening = {
  {
    {
      .id = 0x111,                      // Identifier
      .id_mask  = 0x1f0,                // Mask
    },
  },
 .data.u64 = 0x0LL,                 // Data
};
#endif

// MOB Message Definition: Tx Message
can_mob_t appli_rx_msg = {
  CAN_MOB_NOT_ALLOCATED,            // Handle: by default CAN_MOB_NOT_ALLOCATED
  &msg_rx_listening,                // Pointer on CAN Message
  8,                                // Data length DLC
  CAN_DATA_FRAME,                   // Request type : CAN_DATA_FRAME or CAN_REMOTE_FRAME
  CAN_STATUS_NOT_COMPLETED          // Status: by default CAN_STATUS_NOT_COMPLETED
};

// -----------------------------------------------------------------
// CAN Message Definition: Rx Remote Message
#if defined (__ICCAVR32__)
can_msg_t msg_remote_rx = {
  0x110,                // Identifier
  0x1ff,                // Mask
  0x55AA00000000AA55    // Data Response
};
#else
can_msg_t msg_remote_rx = {
  {
    {
      .id = 0x110,                      // Identifier
      .id_mask  = 0x1ff,                // Mask
    },
  },
 .data.u64 = 0x55AA00000000AA55,        // Data Response
};
#endif

// MOB Message Definition: Rx Remote Message
can_mob_t appli_remote_rx_msg = {
  CAN_MOB_NOT_ALLOCATED,          // Handle: by default CAN_MOB_NOT_ALLOCATED
  &msg_remote_rx,                 // Pointer on CAN Message
  8,                              // Data length DLC
  CAN_REMOTE_FRAME,               // Request type : CAN_DATA_FRAME or CAN_REMOTE_FRAME
  CAN_STATUS_NOT_COMPLETED        // Status: by default CAN_STATUS_NOT_COMPLETED
};

// -----------------------------------------------------------------

#endif /* CAN_CONF_H_ */