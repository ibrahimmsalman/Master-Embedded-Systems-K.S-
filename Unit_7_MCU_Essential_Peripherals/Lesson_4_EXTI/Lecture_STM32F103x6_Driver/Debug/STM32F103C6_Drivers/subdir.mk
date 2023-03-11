################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/stm32f103x8_EXTI_driver.c 

OBJS += \
./STM32F103C6_Drivers/stm32f103x8_EXTI_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/stm32f103x8_EXTI_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/%.o STM32F103C6_Drivers/%.su: ../STM32F103C6_Drivers/%.c STM32F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"F:/study/electric/E.S_K.S/Code/Master-Embedded-Systems-K.S-/Unit_7_MCU_Essential_Peripherals/Lesson_4_EXTI/Lecture_STM32F103x6_Driver/STM32F103C6_Drivers/inc" -include"F:/study/electric/E.S_K.S/Code/Master-Embedded-Systems-K.S-/Unit_7_MCU_Essential_Peripherals/Lesson_4_EXTI/Lecture_STM32F103x6_Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers

clean-STM32F103C6_Drivers:
	-$(RM) ./STM32F103C6_Drivers/stm32f103x8_EXTI_driver.d ./STM32F103C6_Drivers/stm32f103x8_EXTI_driver.o ./STM32F103C6_Drivers/stm32f103x8_EXTI_driver.su

.PHONY: clean-STM32F103C6_Drivers

