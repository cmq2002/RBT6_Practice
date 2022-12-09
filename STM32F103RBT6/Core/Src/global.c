/*
 * global.c
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#include "global.h"

int mode = 0;

int statusAUTO1 = 0;
int statusAUTO2 = 0;
int statusAUTO3 = 0;
int statusAUTO4 = 0;

int statusMODE2_1 = 0;
int statusMODE2_2 = 0;
int statusMODE2_3 = 0;

int statusMODE3_1 = 0;
int statusMODE3_2 = 0;
int statusMODE3_3 = 0;

int statusMODE4_1 = 0;
int statusMODE4_2 = 0;
int statusMODE4_3 = 0;

int AUTO_RED = 0;
int AUTO_GREEN = 0;
int AUTO_YELLOW = 0;

int counterRed = 0;
int counterGreen = 0;
int counterYellow = 0;

void initWaitingTime(void){
	AUTO_RED = 5;
	AUTO_GREEN = 3;
	AUTO_YELLOW = 2;
}

void initVar(void){
	mode = MODE1;

	statusAUTO1 = INIT;
	statusAUTO2 = INIT;
	statusAUTO3 = INIT;
	statusAUTO4 = INIT;

	statusMODE2_1 = INIT;
	statusMODE2_2 = INIT;
	statusMODE2_3 = INIT;

	statusMODE3_1 = INIT;
	statusMODE3_2 = INIT;
	statusMODE3_3 = INIT;

	statusMODE4_1 = INIT;
	statusMODE4_2 = INIT;
	statusMODE4_3 = INIT;

	counterRed = AUTO_RED;
	counterGreen = AUTO_GREEN;
	counterYellow = AUTO_YELLOW;
}
