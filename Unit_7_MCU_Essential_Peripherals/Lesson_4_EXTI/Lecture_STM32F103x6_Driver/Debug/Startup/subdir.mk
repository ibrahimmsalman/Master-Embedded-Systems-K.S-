################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c6tx.s 

OBJS += \
./Startup/startup_stm32f103c6tx.o 

S_DEPS += \
./Startup/startup_stm32f103c6tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 -mcpu=cortex-m3 -g3 -DDEBUG -c -I"F:/study/electric/E.S_K.S/Code/Master-Embedded-Systems-K.S-/Unit_7_MCU_Essential_Peripherals/Lesson_4_EXTI/Lecture_STM32F103x6_Driver/STM32F103C6_Drivers/inc" -include"F:/study/electric/E.S_K.S/Code/Master-Embedded-Systems-K.S-/Unit_7_MCU_Essential_Peripherals/Lesson_4_EXTI/Lecture_STM32F103x6_Driver/STM32F103C6_Drivers/inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f103c6tx.d ./Startup/startup_stm32f103c6tx.o

.PHONY: clean-Startup

