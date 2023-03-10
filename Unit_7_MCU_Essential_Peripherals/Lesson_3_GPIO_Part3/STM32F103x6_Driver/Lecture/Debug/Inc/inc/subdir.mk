################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/inc/LED.c 

OBJS += \
./Inc/inc/LED.o 

C_DEPS += \
./Inc/inc/LED.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/inc/%.o Inc/inc/%.su: ../Inc/inc/%.c Inc/inc/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driverr/Stm32_F103C6_Drivers/inc" -include"C:/Users/Admin/STM32CubeIDE/workspace_1.11.2/Driverr/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-inc

clean-Inc-2f-inc:
	-$(RM) ./Inc/inc/LED.d ./Inc/inc/LED.o ./Inc/inc/LED.su

.PHONY: clean-Inc-2f-inc

