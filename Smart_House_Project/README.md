 Embedded systems project: a Smart House with access control and temperature monitoring capabilities, built using three AVR ATmega32 microcontrollers.
🔐 Smart House Project Features:
🚪 Access Control: 
- Secure passcode entry via keypad.
- Passcode saved in EEPROM to prevent loss during power failures.
- Alarm activation with flashing red LEDs after three incorrect attempts.
- Easy passcode change upon correct entry.
- Alarm deactivation button inside the house.
🌡 Temperature Monitoring and Control: 
- Room temperatures monitored with LM35 sensors.
- Fans with adjustable speeds (Low, Medium, High) based on room temperature.
- Automatic fan shut down below 14°C.
- Exit button to re-enable passcode entry and turn off fans.
💻 Software Modules Used:
MCAL: Port driver, Dio driver, External interrupts driver, Timers driver (PWM), ADC driver, communication protocols (UART, TWI (I2C), SPI)
HAL: LCD driver, Keypad driver, Fan driver, LM35 temperature sensor driver, buttons driver, buzzer driver, LED driver, EEPROM driver
📡 System Architecture:
Entry MCU: Manages the access control system.
Control MCU: Manages the fan speeds and alarm system.
Sensors MCU: Reads and processes temperature data from each room.
This project showcases the integration of various hardware and software components to create a fully functional and automated smart house system.