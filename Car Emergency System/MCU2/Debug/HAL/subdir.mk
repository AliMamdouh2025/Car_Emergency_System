################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Buzzer.c \
../HAL/Potentiometer.c \
../HAL/Servo.c \
../HAL/motor.c 

OBJS += \
./HAL/Buzzer.o \
./HAL/Potentiometer.o \
./HAL/Servo.o \
./HAL/motor.o 

C_DEPS += \
./HAL/Buzzer.d \
./HAL/Potentiometer.d \
./HAL/Servo.d \
./HAL/motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\Utilities" -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\MCAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\HAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\APP" -Wall -g2 -gstabs -O3 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


