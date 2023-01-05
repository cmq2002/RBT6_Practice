/*
 * uart_reading.h
 *
 *  Created on: Dec 11, 2022
 *      Author: acer
 */

#ifndef INC_UART_READING_H_
#define INC_UART_READING_H_

#include "main.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>


#define MAX_CMD_SIZE 3

#define MAX_BUFFER_SIZE 50

extern uint8_t buffer_byte;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t cmd_flag;


void cmd_parser_fsm();

void uart_control_fsm();

#endif /* INC_UART_READING_H_ */
