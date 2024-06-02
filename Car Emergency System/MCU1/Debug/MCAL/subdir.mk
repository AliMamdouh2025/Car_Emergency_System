################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Internal_EEPROM_prg.c \
../MCAL/WatchDog.c \
../MCAL/gpio.c \
../MCAL/pwm.c \
../MCAL/timer1.c \
../MCAL/uart.c 

OBJS += \
./MCAL/Internal_EEPROM_prg.o \
./MCAL/WatchDog.o \
./MCAL/gpio.o \
./MCAL/pwm.o \
./MCAL/timer1.o \
./MCAL/uart.o 

C_DEPS += \
./MCAL/Internal_EEPROM_prg.d \
./MCAL/WatchDog.d \
./MCAL/gpio.d \
./MCAL/pwm.d \
./MCAL/timer1.d \
./MCAL/uart.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Embedded projects and exprience\Shell Car Project\MCU1" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\Utilitiez" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\MCAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\HAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\APP" -Wall -g2 -gstabs -O3 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


