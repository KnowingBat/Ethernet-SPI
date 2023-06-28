/*
 * wiznet.c
 *
 *  Created on: Jun 27, 2023
 *      Author: David
 */

#include "wiznet.h"

const char MSG_Netinfo[] = "Network Information\n";
const char MSG_IP_Address[] = "IP Address: %d.%d.%d.%d\n";
const char MSG_MAC_Address[] = "MAC Address: %x:%x:%x:%x:%x:%x\n";
const char MSG_Gateway_Address[] = "Gateway address: %d.%d.%d.%d\n";
const char MSG_Subnet[] = "Subnet mask: %d.%d.%d.%d\n";
const char MSG_Dns_Address[] = "DNS Address: %d.%d.%d.%d\n";
const char MSG_Status[] = "Status: %s\n";
const char MSG_Port[] = "Port number: %d\n";

void wizchip_select(void){
	HAL_GPIO_WritePin(CS_SPI2_GPIO_Port, CS_SPI2_Pin, GPIO_PIN_RESET);
}

void wizchip_deselect(void){
	HAL_GPIO_WritePin(CS_SPI2_GPIO_Port, CS_SPI2_Pin, GPIO_PIN_SET);
}

uint8_t wizchip_readByte(){
	uint8_t retVal;
	HAL_SPI_Receive(&hspi2, &retVal, 1, 10U);
	return retVal;
}

void wizchip_writeByte(uint8_t value){
	HAL_SPI_Transmit(&hspi2, &value, 1, 10U);
}

void wizchip_readBuff(uint8_t* buff, uint16_t len) {
    HAL_SPI_Receive(&hspi2, buff, len, 10U);
}

void wizchip_writeBuff(uint8_t* buff, uint16_t len) {
    HAL_SPI_Transmit(&hspi2, buff, len, 10U);
}

void display_netinfo(uint8_t mySocket, wiz_NetInfo *netInfo, uint16_t port){
	uint8_t tempString[50];

	uint8_t ip[4];
	uint8_t mac[6];
	uint8_t gw[4];
	uint8_t sn[4];
	uint8_t dns[4];

	memcpy(ip, netInfo->ip, 4);
	memcpy(mac, netInfo->mac, 6);
	memcpy(gw, netInfo->gw, 4);
	memcpy(sn, netInfo->sn, 4);
	memcpy(dns, netInfo->dns, 4);

	sprintf(tempString, "%s", MSG_Netinfo);
	send(mySocket, tempString, strlen(tempString));
	sprintf(tempString, MSG_IP_Address, ip[0],ip[1],ip[2],ip[3]);
	send(mySocket, tempString, strlen(tempString));
	sprintf(tempString, MSG_MAC_Address, mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
	send(mySocket, tempString, strlen(tempString));
	sprintf(tempString, MSG_Gateway_Address, gw[0],gw[1],gw[2],gw[3]);
	send(mySocket, tempString, strlen(tempString));
	sprintf(tempString, MSG_Subnet, sn[0],sn[1],sn[2],sn[3]);
	send(mySocket, tempString, strlen(tempString));
	sprintf(tempString, MSG_Dns_Address, dns[0],dns[1],dns[2],dns[3]);
	send(mySocket, tempString, strlen(tempString));
	sprintf(tempString, MSG_Port, port);
	send(mySocket, tempString, strlen(tempString));
	sprintf(tempString, MSG_Status, "connected");
	send(mySocket, tempString, strlen(tempString));
}




