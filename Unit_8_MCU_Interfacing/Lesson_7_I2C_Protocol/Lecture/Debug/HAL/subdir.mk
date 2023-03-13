################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_SLAVE_EEPROM.c \
../HAL/Keypad.c \
../HAL/LCD.c 

OBJS += \
./HAL/I2C_SLAVE_EEPROM.o \
./HAL/Keypad.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/I2C_SLAVE_EEPROM.d \
./HAL/Keypad.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driver/STM32F103C6_Drivers/inc" -include"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/I2C_SLAVE_EEPROM.d ./HAL/I2C_SLAVE_EEPROM.o ./HAL/I2C_SLAVE_EEPROM.su ./HAL/Keypad.d ./HAL/Keypad.o ./HAL/Keypad.su ./HAL/LCD.d ./HAL/LCD.o ./HAL/LCD.su

.PHONY: clean-HAL

