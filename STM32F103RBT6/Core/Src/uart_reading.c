/*
 * uart_reading.c
 *
 *  Created on: Dec 11, 2022
 *      Author: acer
 */

#include "uart_reading.h"

//extern ADC_HandleTypeDef hadc1;

extern UART_HandleTypeDef huart3;

// globally use
uint8_t buffer_byte;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

// Locally use in automatic_fsm.c
int status1 = INIT;
uint8_t cmd_flag = INIT;
uint8_t cmd_data[MAX_CMD_SIZE];
uint8_t traveler = 0;
uint8_t cmd_data_index = 0;

int isCmdEqualToRST(uint8_t str[]){
	int flag = 0;
	if (str[0] == 'R' && str[1] == 'S' && str[2] == 'T')
		flag = 1;
	else
		flag = 0;
	return flag;
}

int isCmdEqualToOK(uint8_t str[]){
	int flag = 0;
	if (str[0] == 'O' && str[1] == 'K')
		flag = 1;
	else
		flag = 0;
	return flag;
}

void cmd_parser_fsm(){
	switch(status1){
		case INIT_UART:
			if (buffer[traveler] == '!') status1 = READING;
			traveler++;
			if (traveler == MAX_BUFFER_SIZE) traveler = 0;
//			if (buffer_flag == 0){
//				index_buffer = 0;
//				traveler = 0;
//			}
			break;
		case READING:
			if (buffer[traveler] != '!' && buffer[traveler] != '#'){
				cmd_data[cmd_data_index] = buffer[traveler];
				cmd_data_index++;
			}
			if (buffer[traveler] == '#'){
				status1 = STOP;
				cmd_data_index = 0;
			}
			traveler++;
			if (traveler == MAX_BUFFER_SIZE) traveler = 0;
//			if (buffer_flag == 0){
//				index_buffer = 0;
//				traveler = 0;
//			}
			break;
		case STOP:
			if (isCmdEqualToRST(cmd_data)==1){
				cmd_flag = RST;
				setTimer3(1);
			}
			else if (isCmdEqualToOK(cmd_data)==1){
				cmd_flag = OK;
			}
			status1 = INIT;
			break;
		default:
			break;
	}
}


void uart_comms_fsm(){
//	char str[50];
	switch(cmd_flag){
		case RST:
			if (timer3_flag == 1){
				HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
				setTimer3(100);
			}
		    break;
		case OK:
//			ADC_value = -1;
			cmd_flag = INIT;
			break;
		default:
			break;
	}
}
