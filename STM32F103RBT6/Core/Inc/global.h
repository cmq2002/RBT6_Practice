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
#include "app_25LC512.h"
#include "uart_reading.h"
#include "buzzer.h"

/*-------------------------------- Define States -------------------------------*/
#define INIT 0

// For Mode1
#define STATE_RED 1
#define STATE_GREEN 2
#define STATE_YELLOW 3

// For Mode2 and 3
#define PREINC 4
#define PREDEC 5
#define INCREASE 6
#define DECREASE 7
#define SAVE 8

// For uart reading
#define INIT_UART 9
#define READING 10
#define STOP 11
//#define CMD_WAITING 3
//#define CMD_WAITING_O 4
//#define CMD_WAITING_OK 5
//#define CMD_WAITING_R 6
//#define CMD_WAITING_RS 7
//#define CMD_WAITING_RST 10
#define RST 12
#define OK 13
#define UNDEF 14

// Threshold for waiting time
#define UPPER_BOUND 200
#define LOWER_BOUND 1

/*-----------------------------3 modes available--------------------------------*/
#define MODE1  13
#define MODE2  14
#define MODE3  15

/*-------------------------------Global Variables------------------------------*/
//Keep track of current mode
extern int mode;

// Waiting time at each state
extern uint32_t AUTO_RED;
extern uint32_t AUTO_GREEN ;
extern uint32_t AUTO_YELLOW;
extern uint32_t AUTO_RED2[1];
extern uint32_t AUTO_GREEN2[1] ;
extern uint32_t AUTO_YELLOW2[1];
// Counter for the lights
extern int counterRed;
extern int counterGreen;
extern int counterYellow;

// Status for MODE1
extern int statusAUTO;

// Status for MODE2
extern int statusMODE2;

// Status for MODE3
extern int statusMODE3;

void initWaitingTime(void);

void initVar(void);

#endif /* INC_GLOBAL_H_ */
