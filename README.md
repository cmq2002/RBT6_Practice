# HCMUT MCU-MPU Assignment

## General Information:
- Major components: Custom board with STM32F103RBT6 MCU
- Supporting multiple communications protocol: I2C, SPI, UART
- Purpose: Implement a simple traffic light system
- Components' usage:
  - LCD for displaying information
  - Dip switch for select board ID or change mode to test
  - Eprom 25LC512 for saving data
  - UART to update and control the system
  - Watchdog to reset system when having a problem
## About the Project Layout:
- Schematic_Design folder contains the design for all components
- Modules is where we implement the library for each components seperately
- STM32F103RBT6 consists of the whole project with all configurations and source code
  
