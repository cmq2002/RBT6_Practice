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

#define INIT_UART 0

#define READING 1

#define STOP 2

#define CMD_WAITING 3
#define CMD_WAITING_O 4
#define CMD_WAITING_OK 5
#define CMD_WAITING_R 6
#define CMD_WAITING_RS 7
#define CMD_WAITING_RST 10

#define RST 8

#define OK 9

#define MAX_CMD_SIZE 3

#define MAX_BUFFER_SIZE 50

extern uint8_t buffer_byte;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

//extern uint8_t rxBuffer[3];

void cmd_parser_fsm();

void uart_comms_fsm();

#endif /* INC_UART_READING_H_ */
