/*
 * buzzer.c
 *
 *  Created on: Dec 11, 2022
 *      Author: acer
 */

#include "buzzer.h"

extern TIM_HandleTypeDef htim3;
/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// Turn on in x secs and turn off in y secs /////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
static int counterBUZZ = 0; // For Buzzer
void buzzer (uint32_t on, uint32_t off){
	if (on == 0) return;
	counterBUZZ = (counterBUZZ + 1) % (off + on);
	if (counterBUZZ == 0) HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
	if (counterBUZZ == on) HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, RESET);
}

static int counterLED = 0;  // For LED
void ledBlink (uint32_t on, uint32_t off){
	if (on == 0) return;
	counterLED = (counterLED+1) % (on+off);
	if (counterLED == 0) HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, RESET);
	if (counterLED == on) HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, SET);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
////onTime = 1000/delay_time * 1/f * duty/100
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// Var For System Status ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
//const int delay_time = 10;
//const int delay_for_system_status_change = 60000/delay_time;
//static int systemStatus = 0;
//static int counterForSystemStatus = 0;
///////////////////////////////////////////////////////////////////////////////////////////////
//
//void UpdateStatus (void){
//	counterForSystemStatus = (counterForSystemStatus+1) % delay_for_system_status_change;
//	if (counterForSystemStatus == 0)
//		systemStatus = (systemStatus + 1) % 4;
//}
//
//static uint8_t counterForState0 = 0;
//void buzzerStartUp (void){
//	if (counterForState0 % 100 == 0) HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, RESET);
//	if (counterForState0 % 100 == 50) HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
//	if (counterForState0 < 200)	counterForState0++;
//}
//
//void buzzerProcess (void){
//	switch (systemStatus){
//		case 0:
//			buzzerStartUp();
//			break;
//		case 1:
//			buzzer(50,450);
//			counterForState0 = 0;
//			break;
//		case 2:
//			buzzer(50,50);
//			counterForState0 = 0;
//			break;
//		case 3:
//			buzzer(50,0);
//			counterForState0 = 0;
//			break;
//		default:
//			break;
//	}
//}


//uint8_t i = 0;
//uint16_t beep[3] = {1, 1, 1};
//const uint16_t melody[] = {NOTE_C6, NOTE_C6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_C6, 1,
//		NOTE_C6, NOTE_C6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_C6, 1,
//		NOTE_E6, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_G6, 1, 1,
//		NOTE_E6, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_G6, 1, 1,
//		NOTE_G6, NOTE_A6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_C6,
//		NOTE_G6, NOTE_A6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_C6};
//const uint16_t melodyLength = sizeof(melody) / sizeof(uint16_t);
//
//
//void play_music(void){
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 15 + beep[i%3]);
//	TIM3->PSC = 64000/melody[i%melodyLength];
//	i++;
//}
