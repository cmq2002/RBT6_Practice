/*
 * global.c
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#include "global.h"

int mode = 0;

int statusAUTO = 0;

int statusMODE2 = 0;

int statusMODE3 = 0;

int AUTO_RED = 0;
int AUTO_GREEN = 0;
int AUTO_YELLOW = 0;

int counterRed = 0;
int counterGreen = 0;
int counterYellow = 0;

void initWaitingTime(void){
	AUTO_GREEN = 18;
	AUTO_YELLOW = 7;
	AUTO_RED = AUTO_GREEN + AUTO_YELLOW;
}

void initVar(void){
	mode = MODE1;

	statusAUTO = INIT;

	statusMODE2 = INIT;

	statusMODE3 = INIT;

	counterRed = AUTO_RED;
	counterGreen = AUTO_GREEN;
	counterYellow = AUTO_YELLOW;
}
