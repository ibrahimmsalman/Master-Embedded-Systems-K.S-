################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/LCD.c 

OBJS += \
./HAL/LCD/LCD.o 

C_DEPS += \
./HAL/LCD/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/%.o HAL/LCD/%.su: ../HAL/LCD/%.c HAL/LCD/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driver/MCAL" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driver/Services" -include"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driver/Services" -include"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driver/MCAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-LCD

clean-HAL-2f-LCD:
	-$(RM) ./HAL/LCD/LCD.d ./HAL/LCD/LCD.o ./HAL/LCD/LCD.su

.PHONY: clean-HAL-2f-LCD

