/*
 * led_pannel.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Admin
 */

#ifndef INC_LED_PANNEL_H_
#define INC_LED_PANNEL_H_

#include "main.h"

void latchEnable (void);

void latchDisable (void);

void outputEnable (void);

void outputDisable (void);

void clockON (void);

void clockOFF (void);

void dataOUT (GPIO_PinState state);

void ledDisplay1(void);

uint8_t getBitValue (uint32_t data, uint32_t index);

void enableLedPannel(int index);

#endif /* INC_LED_PANNEL_H_ */
