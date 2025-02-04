################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app_25LC512.c \
../Core/Src/app_i2c_lcd.c \
../Core/Src/buzzer.c \
../Core/Src/fsm.c \
../Core/Src/global.c \
../Core/Src/led_pannel.c \
../Core/Src/main.c \
../Core/Src/software_timer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/uart_reading.c 

OBJS += \
./Core/Src/app_25LC512.o \
./Core/Src/app_i2c_lcd.o \
./Core/Src/buzzer.o \
./Core/Src/fsm.o \
./Core/Src/global.o \
./Core/Src/led_pannel.o \
./Core/Src/main.o \
./Core/Src/software_timer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/uart_reading.o 

C_DEPS += \
./Core/Src/app_25LC512.d \
./Core/Src/app_i2c_lcd.d \
./Core/Src/buzzer.d \
./Core/Src/fsm.d \
./Core/Src/global.d \
./Core/Src/led_pannel.d \
./Core/Src/main.d \
./Core/Src/software_timer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/uart_reading.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app_25LC512.d ./Core/Src/app_25LC512.o ./Core/Src/app_25LC512.su ./Core/Src/app_i2c_lcd.d ./Core/Src/app_i2c_lcd.o ./Core/Src/app_i2c_lcd.su ./Core/Src/buzzer.d ./Core/Src/buzzer.o ./Core/Src/buzzer.su ./Core/Src/fsm.d ./Core/Src/fsm.o ./Core/Src/fsm.su ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/led_pannel.d ./Core/Src/led_pannel.o ./Core/Src/led_pannel.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/software_timer.d ./Core/Src/software_timer.o ./Core/Src/software_timer.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/uart_reading.d ./Core/Src/uart_reading.o ./Core/Src/uart_reading.su

.PHONY: clean-Core-2f-Src

