################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS_STACK/TIMER0/TIMERS_Program.c 

OBJS += \
./RTOS_STACK/TIMER0/TIMERS_Program.o 

C_DEPS += \
./RTOS_STACK/TIMER0/TIMERS_Program.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS_STACK/TIMER0/%.o: ../RTOS_STACK/TIMER0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


