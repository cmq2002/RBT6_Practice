# Simple Trafficlight System - HCMUT MCU-MPU Assignment
## General Information:
- Major components: Custom board with STM32F103RBT6 MCU.
- Supporting multiple communications protocol: I2C, SPI, UART...
- Purpose: Implement a simple traffic light system.
- Components' usage:
  - UART Communication to control the system from host computer.
  - LCD for displaying information.
  - Led Pannel for traffic light signal.
  - Dip switch for select board ID or change mode to test.
  - Eprom 25LC512 for saving data.
## About the Project Layout:
- Schematic_Design folder contains the design for all components.
- Modules folder is where we implement the library for each components seperately.
- STM32F103RBT6 folder consists of the whole project with all configurations and source code:
  - global.h & .c: all global variables and labels.
  - led_pannel.h & .c: control the leds.
  - app_i2c_lcd.h & .c: working with lcd.
  - fsm.h & .c:  run the system.
  - uart_reading.h & .c: intercept uart command and execute the corresponding feature.
  - app_25LC512.h & .c: using Eprom to store and fetch data.
  - software_timer: provide a timer .
## About the System's Behavior:
- Initially, system runs in auto mode: Led Panel for trafficlight, LCD displays wait time for each lane and the state (RED, GREEN, YELLOW) of that lane, whenever one lane in YELLOW state, a buzzer will turn on every 1 sec to warn the vehicles slowing down for pedestrian crossing the road.
- We define a set of uart command as following:
  - !R# : Come back to AUTO mode.
  - !1# : Changing wait time for green light, also known as MODE2.
  - !2# : Changing wait time for yellow light, also known as MODE3.
  - !+# : Increase wait time 1 unit.
  - !-# : Decrease wait time 1 unit.
  - !O# : Save any changes and come back to AUTO mode.
- While in MODE2 or MODE3, traffic light will toggle to the corresponding light (ex: green light on both lane on if in MODE2) and a light at the pin PB2 will blink every 1 sec. Besides, LCD will display mode and the current wait time of that mode.

