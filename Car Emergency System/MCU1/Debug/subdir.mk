################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
main.o: ../main.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Embedded projects and exprience\Shell Car Project\MCU1" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\Utilitiez" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\MCAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\HAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU1\APP" -Wall -g2 -gstabs -O3 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


