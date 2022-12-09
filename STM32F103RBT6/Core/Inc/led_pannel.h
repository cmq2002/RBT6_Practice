/*
 * led_pannel.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Admin
 */

#ifndef INC_LED_PANNEL_H_
#define INC_LED_PANNEL_H_

#include "main.h"
#include "global.h"


void latchEnable (void);

void latchDisable (void);

void outputEnable (void);

void outputDisable (void);

void clockON (void);

void clockOFF (void);

void dataOUT (GPIO_PinState state);

uint8_t getBitValue (uint8_t data, uint8_t index);

void ledDisplay1();
void ledDisplay2();
void ledDisplay3();
void ledDisplay4();

void enableLedPannel(int index);

#endif /* INC_LED_PANNEL_H_ */
