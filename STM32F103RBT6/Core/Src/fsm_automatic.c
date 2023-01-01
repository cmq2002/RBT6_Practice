/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2022
 *      Author: acer
 */

#include "fsm_automatic.h"

int num_buffer[2] = {0,0};
int state_buffer[2] = {0,0};

void fsm_automatic_run(void){
	if (mode == MODE1){
		switch (statusAUTO1){
			case INIT:
				statusAUTO1 = STATE_RED;
				setTimer2(1);
				break;
			case STATE_RED:
				state_buffer[0] = STATE_RED;
				if (timer2_flag == 1){
					if (counterRed > AUTO_YELLOW){
						state_buffer[1] = STATE_GREEN;
						enableLedPannel(1);
						num_buffer[0] = counterRed;
						num_buffer[1] = counterRed - counterYellow;
					}
					else{
						state_buffer[1] = STATE_YELLOW;
						enableLedPannel(2);
						num_buffer[0] = counterRed;
						num_buffer[1] = counterRed;
					}
					counterRed--;
					if (counterRed == INIT){
						counterRed = AUTO_RED;
						statusAUTO1 = STATE_GREEN;
					}
					setTimer2(100);
				}
				break;
			case STATE_GREEN:
				state_buffer[0] = STATE_GREEN;
				state_buffer[1] = STATE_RED;
				if (timer2_flag == 1){
					enableLedPannel(3);
					num_buffer[0] = counterGreen;
					num_buffer[1] = counterGreen + counterYellow;
					counterGreen--;
					if (counterGreen == INIT){
						counterGreen = AUTO_GREEN;
						statusAUTO1 = STATE_YELLOW;
					}
					setTimer2(100);
				}
				break;
			case STATE_YELLOW:
				state_buffer[0] = STATE_YELLOW;
				state_buffer[1] = STATE_RED;
				if (timer2_flag == 1){
					enableLedPannel(4);
					num_buffer[0] = counterYellow;
					num_buffer[1] = counterYellow;
					counterYellow--;
					if (counterYellow == INIT){
						counterYellow = AUTO_YELLOW;
						statusAUTO1 = STATE_RED;
					}
					setTimer2(100);
				}
				break;
			default:
				break;
		}


		displayNum(num_buffer[0], num_buffer[1], state_buffer[0], state_buffer[1]);

	}

}
