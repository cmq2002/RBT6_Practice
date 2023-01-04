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
						HAL_GPIO_TogglePin(BUZZER_GPIO_Port,BUZZER_Pin);
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
					HAL_GPIO_TogglePin(BUZZER_GPIO_Port,BUZZER_Pin);
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

	else if (mode == MODE2){
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
		mode_buffer = MODE2;
		time_buffer = AUTO_GREEN;
		enableLedPannel(5);
		switch (statusMODE2){
			case INIT:
				ensureInBoundary();
				break;
			case INCREASE:
				mode2IncProcess();
				statusMODE2=INIT;
				cmd_flag = UNDEF;
				break;
			case DECREASE:
				mode2DecProcess();
				statusMODE2=INIT;
				cmd_flag = UNDEF;
				break;
			case SAVE:
				mode = MODE1;
				//Auto_GREEN -> EPROM
				initVar();
				break;
			default:
				break;
		}
		displayInMode(mode_buffer, time_buffer);
	}

	else if (mode == MODE3){
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
		mode_buffer = MODE3;
		time_buffer = AUTO_YELLOW;
		enableLedPannel(6);
		switch (statusMODE3){
			case INIT:
				ensureInBoundary();
				break;
			case INCREASE:
				mode3IncProcess();
				statusMODE3=INIT;
				cmd_flag = MODE3;
				mode = MODE3;
				break;
			case DECREASE:
				mode3DecProcess();
				statusMODE3=INIT;
				cmd_flag = MODE3;
				mode = MODE3;
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
