################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad.c \
../HAL/LCD.c 

OBJS += \
./HAL/Keypad.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/Keypad.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/study/electric/E.S_K.S/Code/Master-Embedded-Systems-K.S-/Unit_7_MCU_Essential_Peripherals/Lesson_4_EXTI/Lecture_STM32F103x6_Driver/STM32F103C6_Drivers/inc" -include"F:/study/electric/E.S_K.S/Code/Master-Embedded-Systems-K.S-/Unit_7_MCU_Essential_Peripherals/Lesson_4_EXTI/Lecture_STM32F103x6_Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/Keypad.d ./HAL/Keypad.o ./HAL/Keypad.su ./HAL/LCD.d ./HAL/LCD.o ./HAL/LCD.su

.PHONY: clean-HAL

