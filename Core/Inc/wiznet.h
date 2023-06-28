/*
 * wiznet.h
 *
 *  Created on: Jun 27, 2023
 *      Author: David
 */

#ifndef INC_WIZNET_H_
#define INC_WIZNET_H_

#include "main.h"
#include "gpio.h"
#include "spi.h"
#include <string.h>
#include "wizchip_conf.h"
#include <stdio.h>
#include "socket.h"


void wizchip_select(void);
void wizchip_deselect(void);
uint8_t wizchip_readByte(void);
void wizchip_writeByte(uint8_t value);
void wizchip_readBuff(uint8_t* buff, uint16_t len);
void wizchip_writeBuff(uint8_t* buff, uint16_t len);
// Utils
void display_netinfo(uint8_t mySocket, wiz_NetInfo *netInfo, uint16_t port);

#endif /* INC_WIZNET_H_ */
