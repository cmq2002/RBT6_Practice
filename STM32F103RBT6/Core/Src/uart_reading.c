/*
 * uart_reading.c
 *
 *  Created on: Dec 11, 2022
 *      Author: acer
 */
#include "uart_reading.h"

extern UART_HandleTypeDef huart3;

// globally use
uint8_t buffer_byte;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t mode2Inc_flag = 0;
uint8_t mode2Dec_flag = 0;
uint8_t mode3Inc_flag = 0;
uint8_t mode3Dec_flag = 0;

// Locally use in automatic_fsm.c
uint8_t status1 = INIT_UART;
uint8_t cmd_flag = INIT_UART;
uint8_t cmd_data[MAX_CMD_SIZE];
uint8_t cmd_index = 0;

//Another approach
uint8_t cmdParserStatus = INIT_UART;
uint8_t traveler = 0;

int isCmdEqualToRST(uint8_t str[]){
	int flag = 0;
	if (str[0] == 'R')
		flag = 1;
	else
		flag = 0;
	return flag;
}

int isCmdEqualToOK(uint8_t str[]){
	int flag = 0;
	if (str[0] == 'O')
		flag = 1;
	else
		flag = 0;
	return flag;
}

int isCmdEqualTo1(uint8_t str[]){
	int flag = 0;
	if (str[0] == '1')
		flag = 1;
	else
		flag = 0;
	return flag;
}

int isCmdEqualTo2(uint8_t str[]){
	int flag = 0;
	if (str[0] == '2')
		flag = 1;
	else
		flag = 0;
	return flag;
}

int isCmdEqualToInc(uint8_t str[]){
	int flag = 0;
	if (str[0] == '+')
		flag = 1;
	else
		flag = 0;
	return flag;
}

int isCmdEqualToDec(uint8_t str[]){
	int flag = 0;
	if (str[0] == '-')
		flag = 1;
	else
		flag = 0;
	return flag;
}

void cmd_parser_fsm(){
	switch(status1){
		case INIT_UART:
			if (buffer_byte == '!') status1 = READING;
			break;
		case READING:
			if (buffer_byte != '!' && buffer_byte != '#'){
				cmd_data[cmd_index] = buffer_byte;
				cmd_index++;
			}
			else if (buffer_byte == '#'){
				status1 = STOP;
				cmd_index = 0;
			}
			break;
		case STOP:
			if (isCmdEqualToRST(cmd_data)==1){
				cmd_flag = RST;
			}
			else if (isCmdEqualTo1(cmd_data)==1){
				cmd_flag = MODE2;
			}
			else if (isCmdEqualTo2(cmd_data)==1){
				cmd_flag = MODE3;
			}
			else if (isCmdEqualToInc(cmd_data)==1){
				cmd_flag = INCREASE;
			}
			else if (isCmdEqualToDec(cmd_data)==1){
				cmd_flag = DECREASE;
			}
			else if (isCmdEqualToOK(cmd_data)==1){
				cmd_flag = OK;
			}
			else cmd_flag = UNDEF;
			status1 = INIT_UART;
			break;
		default:
			break;
	}
}


void uart_control_fsm(){
	switch (cmd_flag){
	case RST:
		mode = MODE1;
		break;
	case MODE2:
		mode = MODE2;
		break;
	case MODE3:
		mode = MODE3;
		break;
	case INCREASE:
		if (mode == MODE2) statusMODE2 = INCREASE;
		if (mode == MODE3) statusMODE3 = INCREASE;
		break;
	case DECREASE:
		if (mode == MODE2) statusMODE2 = DECREASE;
		if (mode == MODE3) statusMODE3 = DECREASE;
		break;
	case OK:
		if (mode == MODE2) statusMODE2 = SAVE;
		if (mode == MODE3) statusMODE3 = SAVE;
		break;
	default:
		break;
	}
//	if (cmd_flag == RST)
//		mode = MODE1;
//	else if (cmd_flag == OK){
//		if (mode == MODE2) statusMODE2 = SAVE;
//		else if (mode == MODE3) statusMODE3 = SAVE;
//		else return;
//	}
//	else if (cmd_flag == MODE2)
//		mode = MODE2;
//	else if (cmd_flag == MODE3)
//		mode = MODE3;
//	else if (cmd_flag == INCREASE){
//		if (mode == MODE2) {statusMODE2 = INCREASE;}
//		else if (mode == MODE3) {statusMODE3 = INCREASE;}
//		else return;
//	}
//	else if (cmd_flag == DECREASE){
//		if (mode == MODE2) {statusMODE2 = DECREASE;}
//		else if (mode == MODE3) {statusMODE3 = DECREASE;}
//		else return;
//	}
//	else return;
}

//void cmd_parser_fsm(){
//		switch (cmdParserStatus){
//		case INIT_UART:
//			if (buffer[traveler] == '!')
//			{
//				cmdParserStatus = CMD_WAITING;
//			}
//			traveler++;
//			if (buffer_flag == 0)
//			{
//				index_buffer = 0;
//				traveler = 0;
//			}
//			break;
//		case CMD_WAITING:
//			if (buffer[traveler] == 'O')
//			{
//				cmdParserStatus = CMD_WAITING_O;
//			}
//			else if (buffer[traveler] == 'R')
//			{
//				cmdParserStatus = CMD_WAITING_R;
//			}
//			else cmdParserStatus = INIT_UART;
//			traveler++;
//			if (buffer_flag == 0)
//			{
//				index_buffer = 0;
//				traveler = 0;
//			}
//			break;
//	//-----------------------------------------------------
//		case CMD_WAITING_O:
//			if (buffer[traveler] == 'K')
//			{
//				cmdParserStatus = CMD_WAITING_OK;
//			}
//			else cmdParserStatus = INIT_UART;
//			traveler++;
//			if (buffer_flag == 0)
//			{
//				index_buffer = 0;
//				traveler = 0;
//			}
//			break;
//		case CMD_WAITING_OK:
//			if (buffer[traveler] == '#')
//			{
//				cmd_flag = OK;
//				cmdParserStatus = INIT_UART;
//			}
//			else cmdParserStatus = INIT_UART;
//			traveler++;
//			if (buffer_flag == 0)
//			{
//				index_buffer = 0;
//				traveler = 0;
//			}
//			break;
//	//-----------------------------------------------------
//		case CMD_WAITING_R:
//			if (buffer[traveler] == 'S')
//			{
//				cmdParserStatus = CMD_WAITING_RS;
//			}
//			else cmdParserStatus = INIT_UART;
//			traveler++;
//			if (buffer_flag == 0)
//			{
//				index_buffer = 0;
//				traveler = 0;
//			}
//			break;
//		case CMD_WAITING_RS:
//			if (buffer[traveler] == 'T')
//			{
//				cmdParserStatus = CMD_WAITING_RST;
//			}
//			else cmdParserStatus = INIT_UART;
//			traveler++;
//			if (buffer_flag == 0)
//			{
//				index_buffer = 0;
//				traveler = 0;
//			}
//			break;
//		case CMD_WAITING_RST:
//			if (buffer[traveler] == '#')
//			{
//				cmd_flag = RST;
//				cmdParserStatus = INIT_UART;
//			}
//			else cmdParserStatus = INIT_UART;
//			traveler++;
//			if (buffer_flag == 0)
//			{
//				index_buffer = 0;
//				traveler = 0;
//			}
//			break;
//	//-----------------------------------------------------
//		default:
//			break;
//		}
//}
