/*
 * CANopen Object Dictionary.
 *
 * This file was automatically generated with CANopenNode Object
 * Dictionary Editor. DON'T EDIT THIS FILE MANUALLY !!!!
 * Object Dictionary Editor is currently an older, but functional web
 * application. For more info see See 'Object_Dictionary_Editor/about.html' in
 * <http://sourceforge.net/p/canopennode/code_complete/ci/master/tree/>
 * For more information on CANopen Object Dictionary see <CO_SDO.h>.
 *
 * @file        CO_OD.c
 * @author      Janez Paternoster
 * @copyright   2010 - 2016 Janez Paternoster
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


#include "CO_driver.h"
#include "CO_OD.h"
#include "CO_SDO.h"


/*******************************************************************************
   DEFINITION AND INITIALIZATION OF OBJECT DICTIONARY VARIABLES
*******************************************************************************/

/***** Definition for RAM variables *******************************************/
struct sCO_OD_RAM CO_OD_RAM = {
           CO_OD_FIRST_LAST_WORD,

/*1001*/ 0x0,
/*1002*/ 0x0L,
/*1003*/ {0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L},
/*1010*/ {0x3L},
/*1011*/ {0x1L},
/*2100*/ {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
/*2103*/ 0x0,
/*2104*/ 0x0,
/*2107*/ {0x3E8, 0x0, 0x0, 0x0, 0x0},
/*2108*/ {0},
/*2109*/ {0},
/*2110*/ {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},
/*2120*/ {0x5, 0x1234567890ABCDEFLL, 0x234567890ABCDEF1LL, 12.345, 456.789, 0},
/*2130*/ {0x3, {'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 0, 0x0L},

/******************************************SAJAT**********************************/
/*2201*/ {0xD, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD},
/*2202*/ {0x5, 0x1, 0x2, 0x3, 0x4, 0x5},
/*2203*/ {0xD, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD},
/*2204*/ {0xD, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD},
/*2205*/ {0xD, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD},
/*2206*/ {0xD, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD},
/*2207*/ {0x7, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7},
/*2208*/ {0x5, 0x1, 0x2, 0x3, 0x4, 0x5},
/*2209*/ {0x6, 0x0, 0x0, 0x50, 0x40, 0x1, 0x0},
/*220a*/ {0xD, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD},

/*3001*/ 0x8,

/*4001*/ {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
/*4002*/ {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
/*********************************************************************************/

/*6000*/ {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
/*6200*/ {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
/*6401*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
/*6411*/ {0, 0, 0, 0, 0, 0, 0, 0},

           CO_OD_FIRST_LAST_WORD,
};


/***** Definition for EEPROM variables ****************************************/
struct sCO_OD_EEPROM CO_OD_EEPROM = {
           CO_OD_FIRST_LAST_WORD,

/*2106*/ 0x0L,
/*2112*/ {1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},

           CO_OD_FIRST_LAST_WORD,
};


/***** Definition for ROM variables *******************************************/
   struct sCO_OD_ROM CO_OD_ROM = {    //constant variables, stored in flash
           CO_OD_FIRST_LAST_WORD,

/*1000*/ 0x0L,
/*1005*/ 0x40000080L,//0x80 SYNC consumer
/*1006*/ 0x0L,//SYNC period
/*1007*/ 0x0L,
/*1008*/ {'C', 'A', 'N', 'o', 'p', 'e', 'n', 'N', 'o', 'd', 'e'},
/*1009*/ {'3', '.', '0', '0'},
/*100A*/ {'3', '.', '0', '0'},
/*1014*/ 0x80L,
/*1015*/ 0x64,
/*1016*/ {0x0L, 0x0L, 0x0L, 0x0L},
/*1017*/ 0xF7E8, //heartbeat time
/*1018*/ {0x4, 0x0L, 0x0L, 0x0L, 0x0L},
/*1019*/ 0x0,//SYNC counter overflow
/*1029*/ {0x0, 0x0, 0x1, 0x0, 0x0, 0x0},
/*1200*/{{0x2, 0x600L, 0x580L}},

/*1400*/{{0x2, 0x200L, 0xFF},
/*1401*/ {0x2, 0x300L, 0xFE},
/*1402*/ {0x2, 0x400L, 0xFE},
/*1403*/ {0x2, 0x500L, 0xFE}},

/*1600*/{{0x5, 0x22010208L, 0x22020208L, 0x22030208L, 0x22040208L, 0x22050208L, 0x0L, 0x0L, 0x0L},// RPDO Command1
/*1601*/ {0x5, 0x22060208L, 0x22070208L, 0x22080208L, 0x22090208L, 0x220A0208L, 0x0L, 0x0L, 0x0L},// RPDO Command2
/*1602*/ {0x1, 0x30010008L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L},//RPDO Orders
/*1603*/ {0x0, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L}},

/*1800*/{{0x6, 0x180L, 0xFF, 0x0, 0x0, 0x0, 0x0},
/*1801*/ {0x6, 0x280L, 0xFE, 0x0, 0x0, 0x0, 0x0},
/*1802*/ {0x6, 0x380L, 0xFE, 0x0, 0x0, 0x0, 0x0},
/*1803*/ {0x6, 0x480L, 0xFE, 0x0, 0x0, 0x0, 0x0}},


/*1A00*/{{0x8, 0x40010108L, 0x40010208L, 0x40010308L, 0x40010408L, 0x40010508L, 0x40010608L, 0x40010708L, 0x40010808L},
/*1A01*/ {0x8, 0x22090108L,  0x22090408L, 0x22090508L, 0x22090608L, 0x0L, 0x0L, 0x0L, 0x0L},
/*1A02*/ {0x0, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L},
/*1A03*/ {0x0, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L}},

/*1F80*/ 0x4L,//pre-operational a kezdõállapot
/*2101*/ 0x30,
/*2102*/ 0xFA,
/*2111*/ {1L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},

           CO_OD_FIRST_LAST_WORD
};


/*******************************************************************************
   STRUCTURES FOR RECORD TYPE OBJECTS
*******************************************************************************/
/*0x1018*/ const CO_OD_entryRecord_t OD_record1018[5] = {
           {(void*)&CO_OD_ROM.identity.maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.identity.vendorID, 0x85,  4},
           {(void*)&CO_OD_ROM.identity.productCode, 0x85,  4},
           {(void*)&CO_OD_ROM.identity.revisionNumber, 0x85,  4},
           {(void*)&CO_OD_ROM.identity.serialNumber, 0x85,  4}};
/*0x1200*/ const CO_OD_entryRecord_t OD_record1200[3] = {
           {(void*)&CO_OD_ROM.SDOServerParameter[0].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.SDOServerParameter[0].COB_IDClientToServer, 0x85,  4},
           {(void*)&CO_OD_ROM.SDOServerParameter[0].COB_IDServerToClient, 0x85,  4}};
/*0x1400*/ const CO_OD_entryRecord_t OD_record1400[3] = {
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[0].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[0].COB_IDUsedByRPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[0].transmissionType, 0x0D,  1}};
/*0x1401*/ const CO_OD_entryRecord_t OD_record1401[3] = {
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[1].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[1].COB_IDUsedByRPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[1].transmissionType, 0x0D,  1}};
/*0x1402*/ const CO_OD_entryRecord_t OD_record1402[3] = {
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[2].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[2].COB_IDUsedByRPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[2].transmissionType, 0x0D,  1}};
/*0x1403*/ const CO_OD_entryRecord_t OD_record1403[3] = {
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[3].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[3].COB_IDUsedByRPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[3].transmissionType, 0x0D,  1}};
/*0x1600*/ const CO_OD_entryRecord_t OD_record1600[9] = {
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject8, 0x8D,  4}};
/*0x1601*/ const CO_OD_entryRecord_t OD_record1601[9] = {
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[1].mappedObject8, 0x8D,  4}};
/*0x1602*/ const CO_OD_entryRecord_t OD_record1602[9] = {
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[2].mappedObject8, 0x8D,  4}};
/*0x1603*/ const CO_OD_entryRecord_t OD_record1603[9] = {
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.RPDOMappingParameter[3].mappedObject8, 0x8D,  4}};
/*0x1800*/ const CO_OD_entryRecord_t OD_record1800[7] = {
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].COB_IDUsedByTPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].transmissionType, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].inhibitTime, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].compatibilityEntry, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].eventTimer, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].SYNCStartValue, 0x0D,  1}};
/*0x1801*/ const CO_OD_entryRecord_t OD_record1801[7] = {
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[1].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[1].COB_IDUsedByTPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[1].transmissionType, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[1].inhibitTime, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[1].compatibilityEntry, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[1].eventTimer, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[1].SYNCStartValue, 0x0D,  1}};
/*0x1802*/ const CO_OD_entryRecord_t OD_record1802[7] = {
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[2].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[2].COB_IDUsedByTPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[2].transmissionType, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[2].inhibitTime, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[2].compatibilityEntry, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[2].eventTimer, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[2].SYNCStartValue, 0x0D,  1}};
/*0x1803*/ const CO_OD_entryRecord_t OD_record1803[7] = {
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[3].maxSubIndex, 0x05,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[3].COB_IDUsedByTPDO, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[3].transmissionType, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[3].inhibitTime, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[3].compatibilityEntry, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[3].eventTimer, 0x8D,  2},
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[3].SYNCStartValue, 0x0D,  1}};
/*0x1A00*/ const CO_OD_entryRecord_t OD_record1A00[9] = {
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject8, 0x8D,  4}};
/*0x1A01*/ const CO_OD_entryRecord_t OD_record1A01[9] = {
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[1].mappedObject8, 0x8D,  4}};
/*0x1A02*/ const CO_OD_entryRecord_t OD_record1A02[9] = {
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[2].mappedObject8, 0x8D,  4}};
/*0x1A03*/ const CO_OD_entryRecord_t OD_record1A03[9] = {
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].numberOfMappedObjects, 0x0D,  1},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject1, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject2, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject3, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject4, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject5, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject6, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject7, 0x8D,  4},
           {(void*)&CO_OD_ROM.TPDOMappingParameter[3].mappedObject8, 0x8D,  4}};
/*0x2120*/ const CO_OD_entryRecord_t OD_record2120[6] = {
           {(void*)&CO_OD_RAM.testVar.maxSubIndex, 0x06,  1},
           {(void*)&CO_OD_RAM.testVar.I64, 0xBE,  8},
           {(void*)&CO_OD_RAM.testVar.U64, 0xBE,  8},
           {(void*)&CO_OD_RAM.testVar.R32, 0xBE,  4},
           {(void*)&CO_OD_RAM.testVar.R64, 0xBE,  8},
           {0, 0x0E,  0}};
/*0x2130*/ const CO_OD_entryRecord_t OD_record2130[4] = {
           {(void*)&CO_OD_RAM.time.maxSubIndex, 0x06,  1},
           {(void*)&CO_OD_RAM.time.string[0], 0x06, 30},
           {(void*)&CO_OD_RAM.time.epochTimeBaseMs, 0x8E,  8},
           {(void*)&CO_OD_RAM.time.epochTimeOffsetMs, 0xBE,  4}};

/*0x2201*/ const CO_OD_entryRecord_t OD_record2201[14] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.maxSubIndex, 0x2E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Status, 0x2E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Decay_latch, 0x2E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Decay_act, 0x2E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Current_latch, 0x2E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Current_act, 0x2E, 1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Speed_latch, 0x2E,  2},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Speed_act, 0x2E,  2},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Position_latch, 0x2E,  2},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Position_act, 0x2E,  2},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Direction_latch, 0x2E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Direction_act, 0x2E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Dispenser.Limit_switch, 0x2E,  1}};

/*0x2202*/ const CO_OD_entryRecord_t OD_record2202[6] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Granulate_Level_Sensor.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Level_Sensor.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Level_Sensor.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Granulate_Level_Sensor.Level, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Level_Sensor.Gain, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Granulate_Level_Sensor.Offset, 0x0E,  1}};

/*0x2203*/ const CO_OD_entryRecord_t OD_record2203[14] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Knife.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Knife.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Knife.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
   		   {(void*)&CO_OD_RAM.Knife.Decay_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Knife.Decay_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Knife.Current_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Knife.Current_act, 0x0E, 1},
		   {(void*)&CO_OD_RAM.Knife.Speed_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Knife.Speed_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Knife.Position_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Knife.Position_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Knife.Direction_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Knife.Direction_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Knife.Limit_switch, 0x0E,  1}};

/*0x2204*/ const CO_OD_entryRecord_t OD_record2204[14] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Compression_Press.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Compression_Press.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Compression_Press.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Compression_Press.Decay_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Compression_Press.Decay_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Compression_Press.Current_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Compression_Press.Current_act, 0x0E, 1},
		   {(void*)&CO_OD_RAM.Compression_Press.Speed_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Compression_Press.Speed_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Compression_Press.Position_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Compression_Press.Position_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Compression_Press.Direction_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Compression_Press.Direction_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Compression_Press.Limit_switch, 0x0E,  1}};

/*0x2205*/ const CO_OD_entryRecord_t OD_record2205[14] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Extrusion_Press.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Extrusion_Press.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Extrusion_Press.Decay_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Decay_act, 0x0E,  1},
   		   {(void*)&CO_OD_RAM.Extrusion_Press.Current_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Current_act, 0x0E, 1},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Speed_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Speed_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Position_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Position_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Direction_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Direction_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Extrusion_Press.Limit_switch, 0x0E,  1}};

/*0x2206*/ const CO_OD_entryRecord_t OD_record2206[14] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Main_Axis.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Main_Axis.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Main_Axis.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Main_Axis.Decay_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Main_Axis.Decay_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Main_Axis.Current_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Main_Axis.Current_act, 0x0E, 1},
   		   {(void*)&CO_OD_RAM.Main_Axis.Speed_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Main_Axis.Speed_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Main_Axis.Position_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Main_Axis.Position_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Main_Axis.Direction_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Main_Axis.Direction_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Main_Axis.Limit_switch, 0x0E,  1}};

/*0x2207*/ const CO_OD_entryRecord_t OD_record2207[8] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Water_Dispenser.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Dispenser.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Dispenser.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Water_Dispenser.Value_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Water_Dispenser.Flowmeter_Value_set, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Water_Dispenser.Flowmeter_Gain, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Dispenser.Flowmeter_Offset, 0x0E, 1},
		   {(void*)&CO_OD_RAM.Water_Dispenser.Valve_status, 0x0E,  1}};

/*0x2208*/ const CO_OD_entryRecord_t OD_record2208[6] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Water_Pressure_Sensor.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Pressure_Sensor.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Pressure_Sensor.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Water_Pressure_Sensor.Pressure, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Pressure_Sensor.Gain, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Pressure_Sensor.Offset, 0x0E,  1}};

/*0x2209*/ const CO_OD_entryRecord_t OD_record2209[7] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Water_Heating.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Heating.Status, 0x6E,  1},
		   {(void*)&CO_OD_RAM.Water_Heating.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Water_Heating.Temperature_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Water_Heating.Temperature_act, 0x6E,  1},
		   {(void*)&CO_OD_RAM.Water_Heating.Type, 0x6E,  1},
		   {(void*)&CO_OD_RAM.Water_Heating.Heating_Status, 0x6E,  1}};

/*0x220A*/ const CO_OD_entryRecord_t OD_record220A[14] = {/*attribútumok nem jók ez még csak teszt*/
		   {(void*)&CO_OD_RAM.Conveyor.maxSubIndex, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Conveyor.Status, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Conveyor.ControlWord, 0x1E, 1},//1E=>RAM&SDO_read & SDO_write & RPDO_map
		   {(void*)&CO_OD_RAM.Conveyor.Decay_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Conveyor.Decay_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Conveyor.Current_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Conveyor.Current_act, 0x0E, 1},
		   {(void*)&CO_OD_RAM.Conveyor.Speed_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Conveyor.Speed_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Conveyor.Position_latch, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Conveyor.Position_act, 0x0E,  2},
		   {(void*)&CO_OD_RAM.Conveyor.Direction_latch, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Conveyor.Direction_act, 0x0E,  1},
		   {(void*)&CO_OD_RAM.Conveyor.Limit_switch, 0x0E,  1}};

///*0x4001*/ const CO_OD_entryRecord_t OD_record4001[13] = {/*attribútumok nem jók ez még csak teszt*/
		   //{(void*)&CO_OD_RAM.Error.maxSubIndex, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub1, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub2, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub3, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub4, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub5, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub6, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub7, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub8, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_sub9, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_subA, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_subB, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Error.Error_subC, 0x6E,  1}};
//
///*0x4002*/ const CO_OD_entryRecord_t OD_record4002[13] = {/*attribútumok nem jók ez még csak teszt*/
		   //{(void*)&CO_OD_RAM.Warning.maxSubIndex, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub1, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub2, 0x6E, 1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub3, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub4, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub5, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub6, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub7, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_sub8, 0x6E,  1},
   		   //{(void*)&CO_OD_RAM.Warning.Warning_sub9, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_subA, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_subB, 0x6E,  1},
		   //{(void*)&CO_OD_RAM.Warning.Warning_subC, 0x6E,  1}};
//

/*******************************************************************************
   OBJECT DICTIONARY
*******************************************************************************/
const CO_OD_entry_t CO_OD[CO_OD_NoOfElements] = {
{0x1000, 0x00, 0x85,  4, (void*)&CO_OD_ROM.deviceType},
{0x1001, 0x00, 0x36,  1, (void*)&CO_OD_RAM.errorRegister},
{0x1002, 0x00, 0xB6,  4, (void*)&CO_OD_RAM.manufacturerStatusRegister},
{0x1003, 0x08, 0x8E,  4, (void*)&CO_OD_RAM.preDefinedErrorField[0]},
{0x1005, 0x00, 0x8D,  4, (void*)&CO_OD_ROM.COB_ID_SYNCMessage},
{0x1006, 0x00, 0x8D,  4, (void*)&CO_OD_ROM.communicationCyclePeriod},
{0x1007, 0x00, 0x8D,  4, (void*)&CO_OD_ROM.synchronousWindowLength},
{0x1008, 0x00, 0x05, 11, (void*)&CO_OD_ROM.manufacturerDeviceName[0]},
{0x1009, 0x00, 0x05,  4, (void*)&CO_OD_ROM.manufacturerHardwareVersion[0]},
{0x100A, 0x00, 0x05,  4, (void*)&CO_OD_ROM.manufacturerSoftwareVersion[0]},
{0x1010, 0x01, 0x8E,  4, (void*)&CO_OD_RAM.storeParameters[0]},
{0x1011, 0x01, 0x8E,  4, (void*)&CO_OD_RAM.restoreDefaultParameters[0]},
{0x1014, 0x00, 0x85,  4, (void*)&CO_OD_ROM.COB_ID_EMCY},
{0x1015, 0x00, 0x8D,  2, (void*)&CO_OD_ROM.inhibitTimeEMCY},
{0x1016, 0x04, 0x8D,  4, (void*)&CO_OD_ROM.consumerHeartbeatTime[0]},
{0x1017, 0x00, 0x8D,  2, (void*)&CO_OD_ROM.producerHeartbeatTime},
{0x1018, 0x04, 0x00,  0, (void*)&OD_record1018},
{0x1019, 0x00, 0x0D,  1, (void*)&CO_OD_ROM.synchronousCounterOverflowValue},
{0x1029, 0x06, 0x0D,  1, (void*)&CO_OD_ROM.errorBehavior[0]},
{0x1200, 0x02, 0x00,  0, (void*)&OD_record1200},
{0x1400, 0x02, 0x00,  0, (void*)&OD_record1400},
{0x1401, 0x02, 0x00,  0, (void*)&OD_record1401},
{0x1402, 0x02, 0x00,  0, (void*)&OD_record1402},
{0x1403, 0x02, 0x00,  0, (void*)&OD_record1403},
{0x1600, 0x08, 0x00,  0, (void*)&OD_record1600},
{0x1601, 0x08, 0x00,  0, (void*)&OD_record1601},
{0x1602, 0x08, 0x00,  0, (void*)&OD_record1602},
{0x1603, 0x08, 0x00,  0, (void*)&OD_record1603},
{0x1800, 0x06, 0x00,  0, (void*)&OD_record1800},
{0x1801, 0x06, 0x00,  0, (void*)&OD_record1801},
{0x1802, 0x06, 0x00,  0, (void*)&OD_record1802},
{0x1803, 0x06, 0x00,  0, (void*)&OD_record1803},
{0x1A00, 0x08, 0x00,  0, (void*)&OD_record1A00},
{0x1A01, 0x08, 0x00,  0, (void*)&OD_record1A01},
{0x1A02, 0x08, 0x00,  0, (void*)&OD_record1A02},
{0x1A03, 0x08, 0x00,  0, (void*)&OD_record1A03},
{0x1F80, 0x00, 0x8D,  4, (void*)&CO_OD_ROM.NMTStartup},
{0x2100, 0x00, 0x36, 10, (void*)&CO_OD_RAM.errorStatusBits[0]},
{0x2101, 0x00, 0x0D,  1, (void*)&CO_OD_ROM.CANNodeID},
{0x2102, 0x00, 0x8D,  2, (void*)&CO_OD_ROM.CANBitRate},
{0x2103, 0x00, 0x8E,  2, (void*)&CO_OD_RAM.SYNCCounter},
{0x2104, 0x00, 0x86,  2, (void*)&CO_OD_RAM.SYNCTime},
{0x2106, 0x00, 0x87,  4, (void*)&CO_OD_EEPROM.powerOnCounter},
{0x2107, 0x05, 0xBE,  2, (void*)&CO_OD_RAM.performance[0]},
{0x2108, 0x01, 0xB6,  2, (void*)&CO_OD_RAM.temperature[0]},
{0x2109, 0x01, 0xB6,  2, (void*)&CO_OD_RAM.voltage[0]},
{0x2110, 0x10, 0xFE,  4, (void*)&CO_OD_RAM.variableInt32[0]},
{0x2111, 0x10, 0xFD,  4, (void*)&CO_OD_ROM.variableROMInt32[0]},
{0x2112, 0x10, 0xFF,  4, (void*)&CO_OD_EEPROM.variableNVInt32[0]},
{0x2120, 0x05, 0x00,  0, (void*)&OD_record2120},
{0x2130, 0x03, 0x00,  0, (void*)&OD_record2130},
/********************************************************************/
{0x2201, 0x0D, 0x00,  0, (void*)&OD_record2201},//attribútumok még nem stimmelnek
{0x2202, 0x05, 0x00,  0, (void*)&OD_record2202},//maxsubindexet be kell állítani
{0x2203, 0x0D, 0x00,  0, (void*)&OD_record2203},
{0x2204, 0x0D, 0x00,  0, (void*)&OD_record2204},
{0x2205, 0x0D, 0x00,  0, (void*)&OD_record2205},
{0x2206, 0x0D, 0x00,  0, (void*)&OD_record2206},
{0x2207, 0x07, 0x00,  0, (void*)&OD_record2207},
{0x2208, 0x05, 0x00,  0, (void*)&OD_record2208},
{0x2209, 0x06, 0x00,  0, (void*)&OD_record2209},
{0x220A, 0x0D, 0x00,  0, (void*)&OD_record220A},

{0x3001, 0x00, 0x1E,  1, (void*)&CO_OD_RAM.Fryer_OrdersWaiting},  //attríbútum: 1E=>RAM&SDO_read & SDO_write & RPDO_map
{0x4001, 0x08, 0x6E,  1, (void*)&CO_OD_RAM.Error[0]/*OD_record4001*/},
{0x4002, 0x08, 0x6E,  1, (void*)&CO_OD_RAM.Warning[0]/*OD_record4002*/},
/***********************************************************************/
{0x6000, 0x08, 0x76,  1, (void*)&CO_OD_RAM.readInput8Bit[0]},
{0x6200, 0x08, 0x3E,  1, (void*)&CO_OD_RAM.writeOutput8Bit[0]},
{0x6401, 0x0C, 0xB6,  2, (void*)&CO_OD_RAM.readAnalogueInput16Bit[0]},
{0x6411, 0x08, 0xBE,  2, (void*)&CO_OD_RAM.writeAnalogueOutput16Bit[0]},
};

