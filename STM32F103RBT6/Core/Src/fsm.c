/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#include "fsm.h"

int num_buffer[2] = {0,0};
int state_buffer[2] = {0,0};
int mode_buffer = 0;
int time_buffer = 0;

void ensureInBoundary(){
	if (AUTO_RED > UPPER_BOUND) AUTO_RED = UPPER_BOUND;
	if (AUTO_RED < LOWER_BOUND) AUTO_RED = LOWER_BOUND;
	if (AUTO_GREEN > UPPER_BOUND) AUTO_GREEN = UPPER_BOUND;
	if (AUTO_GREEN < LOWER_BOUND) AUTO_GREEN = LOWER_BOUND;
	if (AUTO_YELLOW > UPPER_BOUND) AUTO_YELLOW = UPPER_BOUND;
	if (AUTO_YELLOW < LOWER_BOUND) AUTO_YELLOW = LOWER_BOUND;
}

void mode2IncProcess(){
	AUTO_GREEN++;
	time_buffer = AUTO_GREEN;
	AUTO_RED = AUTO_GREEN + AUTO_YELLOW;
	ensureInBoundary();
}

void mode2DecProcess(){
	AUTO_GREEN--;
	time_buffer = AUTO_GREEN;
	AUTO_RED = AUTO_GREEN + AUTO_YELLOW;
	ensureInBoundary();
}

void mode3IncProcess(){
	AUTO_YELLOW++;
	time_buffer = AUTO_YELLOW;
	AUTO_RED = AUTO_GREEN + AUTO_YELLOW;
	ensureInBoundary();
}

void mode3DecProcess(){
	AUTO_YELLOW--;
	time_buffer = AUTO_YELLOW;
	AUTO_RED = AUTO_GREEN + AUTO_YELLOW;
	ensureInBoundary();
}

void fsm_run(void){
	if (mode == MODE1){
		switch (statusAUTO){
			case INIT:
				statusAUTO = STATE_RED;
				setTimer2(1);
				break;
			case STATE_RED:
				state_buffer[0] = STATE_RED;
				if (timer2_flag == 1){
					if (counterRed > AUTO_YELLOW){
						state_buffer[1] = STATE_GREEN;
						enableLedPannel(1);
						HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,RESET);
						num_buffer[0] = counterRed;
						num_buffer[1] = counterRed - counterYellow;
					}
					else{
						state_buffer[1] = STATE_YELLOW;
						enableLedPannel(2);
//						HAL_GPIO_TogglePin(BUZZER_GPIO_Port,BUZZER_Pin);
						num_buffer[0] = counterRed;
						num_buffer[1] = counterRed;
					}
					counterRed--;
					if (counterRed == INIT){
						counterRed = AUTO_RED;
						statusAUTO = STATE_GREEN;
					}
					setTimer2(100);
				}
				break;
			case STATE_GREEN:
				state_buffer[0] = STATE_GREEN;
				state_buffer[1] = STATE_RED;
				if (timer2_flag == 1){
					enableLedPannel(3);
					HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,RESET);
					num_buffer[0] = counterGreen;
					num_buffer[1] = counterGreen + counterYellow;
					counterGreen--;
					if (counterGreen == INIT){
						counterGreen = AUTO_GREEN;
						statusAUTO = STATE_YELLOW;
					}
					setTimer2(100);
				}
				break;
			case STATE_YELLOW:
				state_buffer[0] = STATE_YELLOW;
				state_buffer[1] = STATE_RED;
				if (timer2_flag == 1){
					enableLedPannel(4);
//					HAL_GPIO_TogglePin(BUZZER_GPIO_Port,BUZZER_Pin);
					num_buffer[0] = counterYellow;
					num_buffer[1] = counterYellow;
					counterYellow--;
					if (counterYellow == INIT){
						counterYellow = AUTO_YELLOW;
						statusAUTO = STATE_RED;
					}
					setTimer2(100);
				}
				break;
			default:
				break;
		}
		displayNum(num_buffer[0], num_buffer[1], state_buffer[0], state_buffer[1]);
	}

	if (mode == MODE2){
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
		mode_buffer = MODE2;
		time_buffer = AUTO_GREEN;
		enableLedPannel(5);
		switch (statusMODE2){
			case INIT:
				ensureInBoundary();
				break;
			case PREINC:
				statusMODE2 = INCREASE;
				setTimer3(1);
				break;
			case INCREASE:
				if (timer3_flag == 1){
					mode2IncProcess();
					setTimer3(300);
				}
				break;
			case PREDEC:
				statusMODE2 = DECREASE;
				setTimer4(1);
				break;
			case DECREASE:
				if (timer4_flag == 1){
					mode2DecProcess();
					setTimer4(300);
				}
				break;
			case SAVE:
				mode = MODE1;
				initVar();
				break;
			default:
				break;
		}
		displayInMode(mode_buffer, time_buffer);
	}

	if (mode == MODE3){
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
		mode_buffer = MODE3;
		time_buffer = AUTO_YELLOW;
		enableLedPannel(6);
		switch (statusMODE3){
			case INIT:
				ensureInBoundary();
				break;
			case PREINC:
				statusMODE3 = INCREASE;
				setTimer5(1);
				break;
			case INCREASE:
				if (timer5_flag == 1){
					mode3IncProcess();
					setTimer5(300);
				}
				break;
			case PREDEC:
				statusMODE3 = DECREASE;
				setTimer6(1);
				break;
			case DECREASE:
				if (timer6_flag == 1){
					mode3DecProcess();
					setTimer6(300);
				}
				break;
			case SAVE:
				mode = MODE1;
				initVar();
				break;
			default:
				break;
		}
		displayInMode(mode_buffer, time_buffer);
	}

	else return;
}
