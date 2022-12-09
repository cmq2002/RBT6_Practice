/*
 * led_pannel.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Admin
 */

#include "led_pannel.h"

void latchEnable (void){
	HAL_GPIO_WritePin(LED_LE_GPIO_Port, LED_LE_Pin, RESET);
}

void latchDisable (void){
	HAL_GPIO_WritePin(LED_LE_GPIO_Port, LED_LE_Pin, SET);
}

void outputEnable (void){
	HAL_GPIO_WritePin(LED_OE_GPIO_Port, LED_OE_Pin, SET);
}

void outputDisable (void){
	HAL_GPIO_WritePin(LED_OE_GPIO_Port, LED_OE_Pin, RESET);
}

void clockON (void){
	HAL_GPIO_WritePin(LED_SCK_GPIO_Port, LED_SCK_Pin, RESET);
}

void clockOFF (void){
	HAL_GPIO_WritePin(LED_SCK_GPIO_Port, LED_SCK_Pin, SET);
}

void dataOUT (GPIO_PinState state){
	HAL_GPIO_WritePin(LED_SDI_GPIO_Port, LED_SDI_Pin, state);
}

uint8_t getBitValue (uint8_t data, uint8_t index){
	data = (data >> index) & 0x01;
	return data;
}


uint32_t data1[4] = {0x80, 0x30, 0x00, 0x00};
uint32_t data2[4] = {0x40, 0x40, 0x21, 0x0D};

void ledDisplay1 (void){	//red1 + green2
	uint8_t i;
	uint32_t temp1 = data1[0];
	uint32_t temp2 = data2[0];
	latchDisable();
	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp1, i));
		clockON();
	}

	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp2, i));
		clockON();
	}
	latchEnable();
}

void ledDisplay2 (void){	//red1 + yellow2
	uint8_t i;
	uint32_t temp1 = data1[1];
	uint32_t temp2 = data2[1];
	latchDisable();
	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp1, i));
		clockON();
	}

	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp2, i));
		clockON();
	}
	latchEnable();
}

void ledDisplay3 (void){	//Green1 + Red2
	uint8_t i;
	uint32_t temp1 = data1[2];
	uint32_t temp2 = data2[2];
	latchDisable();
	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp1, i));
		clockON();
	}

	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp2, i));
		clockON();
	}
	latchEnable();
}

void ledDisplay4 (void){	//Yellow1 + Red2
	uint8_t i;
	uint32_t temp1 = data1[3];
	uint32_t temp2 = data2[3];
	latchDisable();
	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp1, i));
		clockON();
	}

	for(i = 0; i < 8; i++){
		clockOFF();
		dataOUT(getBitValue(temp2, i));
		clockON();
	}
	latchEnable();
}


void enableLedPannel (int index){
	switch (index){
		case 1:
			ledDisplay1();
			break;
		case 2:
			ledDisplay2();
			break;
		case 3:
			ledDisplay3();
			break;
		case 4:
			ledDisplay4();
			break;
		default:
			break;
	}
}
