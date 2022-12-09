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
## For team members:
- You only need to clone the project in the first time
- Anything changes locally is submitted to the Modules folder as source code file only.
- It is recommended that you should visit the STM32CubeIde to download the latest version 1.11.0 to avoid conflict. Before doing that, please uinstall your current version which is 1.7.0.
- Fresh installing from the website will eliminate error occurs when we debug the code using STLink-V2 (Note: Using update feature is not a good choice as error will be prompted)  
