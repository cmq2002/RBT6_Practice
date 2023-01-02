/*
 * global.h
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "led_pannel.h"
#include "app_i2c_lcd.h"
#include "uart_reading.h"
#include "buzzer.h"

/*-------------------------------- Define States -------------------------------*/
#define INIT 0

// For Mode1
#define STATE_RED 1
#define STATE_GREEN 2
#define STATE_YELLOW 3

// For Mode2 and 3
#define TOGGLE 1
#define INCREASE 2
#define DECREASE 3
#define SAVE 4

// Threshold for waiting time
#define UPPER_BOUND 999
#define LOWER_BOUND 1

/*-----------------------------3 modes available--------------------------------*/
#define MODE1  1
#define MODE2  2
#define MODE3  3

/*-------------------------------Global Variables------------------------------*/
//Keep track of current mode
extern int mode;

// Waiting time at each state
extern int AUTO_RED;
extern int AUTO_GREEN ;
extern int AUTO_YELLOW;

// Counter for the lights
extern int counterRed;
extern int counterGreen;
extern int counterYellow;

// Status for MODE1
extern int statusAUTO1; // For displaying traffic light
extern int statusAUTO2;
extern int statusAUTO3; // For displaying countdown number
extern int statusAUTO4; // For changing MODEs

// Status for MODE2
extern int statusMODE2_1; // For blink led
extern int statusMODE2_2; // For display mode and value
extern int statusMODE2_3; // For making changes in waiting time

// Status for MODE3
extern int statusMODE3_1; // For blink led
extern int statusMODE3_2; // For display mode and value
extern int statusMODE3_3; // For making changes in waiting time

void initWaitingTime(void);

void initVar(void);

#endif /* INC_GLOBAL_H_ */
