/******************************************************************************
 *
 * Module: Application
 *
 * File Name: Application.c
 *
 * Description: Application file
 *
 * Author: Ali Mamdouh
 *
 *******************************************************************************/
#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "common_macros.h"
#include "std_types.h"
#include "adc.h"
#include "motor.h"
#include "Potentiometer.h"
#include "Servo.h"
#include "Buzzer.h"
#include "gpio.h"
#include "Application.h"




/*******************************************************************************
 *                     initialize Global Variables                             *
 *******************************************************************************/
/*Flags global variables*/
boolean Stop_Machine_Flag = 0;

/*Callback global variables*/
uint8 g_UartReceiveTemp;

/*State global variable*/
uint8 State = NORMAL_STATE;




/*******************************************************************************
 *                      Functions implementation                                  *
 *******************************************************************************/
void Machine(void)
{
	if(Stop_Machine_Flag == 0)
	{
		Volt_Percent_t Machine_Volt = Voltage_Percent();

		switch(Machine_Volt)
		{
		case Volt_10_Percent:
			DcMotor_Rotate(CW, 10);
			break;
		case Volt_20_Percent:
			DcMotor_Rotate(CW, 20);
			break;

		case Volt_30_Percent:
			DcMotor_Rotate(CW, 30);
			break;

		case Volt_40_Percent:
			DcMotor_Rotate(CW, 40);
			break;

		case Volt_50_Percent:
			DcMotor_Rotate(CW, 50);
			break;

		case Volt_60_Percent:
			DcMotor_Rotate(CW, 60);
			break;

		case Volt_70_Percent:
			DcMotor_Rotate(CW, 70);
			break;

		case Volt_80_Percent:
			DcMotor_Rotate(CW, 80);
			break;

		case Volt_90_Percent:
			DcMotor_Rotate(CW, 90);
			break;

		case Volt_100_Percent:
			DcMotor_Rotate(CW, 100);
			break;

		}
	}
	else
	{
		/*Do nothing*/
	}
}





void UartReceiveMessage(void)
{

	g_UartReceiveTemp = UART_recieveByte();
}






void Normal_State(void)
{
	/*Running  the machine*/
	Machine();

	/*Temperature states*/
	if(g_UartReceiveTemp < 20)
	{
		State = NORMAL_STATE;
		GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, 1);
		GPIO_writePin(RED_LED_PORT, RED_LED_PIN, 0);
		GPIO_writePin(YELLOW_LED_PORT, YELLOW_LED_PIN, 0);
		Stop_Machine_Flag = 0;
	}
	else if(g_UartReceiveTemp < 40)
	{
		State = NORMAL_STATE;
		GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, 0);
		GPIO_writePin(RED_LED_PORT, RED_LED_PIN, 0);
		GPIO_writePin(YELLOW_LED_PORT, YELLOW_LED_PIN, 1);
		Stop_Machine_Flag = 0;
	}
	else if(g_UartReceiveTemp <= 50)
	{
		State = NORMAL_STATE;
		GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, 0);
		GPIO_writePin(RED_LED_PORT, RED_LED_PIN, 1);
		GPIO_writePin(YELLOW_LED_PORT, YELLOW_LED_PIN, 0);
		Stop_Machine_Flag = 0;
	}
	else if(g_UartReceiveTemp <= LM35_VOLTAGE_LIMIT)
	{
		State = EMERGENCY_STATE;
		DcMotor_Rotate(STOP, 0);
		Stop_Machine_Flag = 1;
		Buzzer_on();
	}
	else if(g_UartReceiveTemp == MACHINE_STOP)
	{
		State = NORMAL_STATE;
		DcMotor_Rotate(STOP, 0);
		Stop_Machine_Flag = 1;
	}
	else
	{
		/*Do nothing*/
	}

}


/*
 * 		Servo_SetPostion(Position_0);
		_delay_ms(SERRVO_PERIOD_MS);
		Servo_Off();
 *
 *
 * */


void Emergency_State(void)
{
	if((g_UartReceiveTemp <= 50) || (g_UartReceiveTemp == MACHINE_STOP))
	{
		State =  NORMAL_STATE;
		Buzzer_off();
	}
	else if(g_UartReceiveTemp == ABNORMAL_UART)
	{
		State =  ABNORMAL_STATE;
		Servo_SetPostion(Position_90);
	}
	else
	{
		/*Do nothing*/
	}

}





void Abnormal_State(void)
{
	/*Wait 5 seconds in abnormal State*/
	_delay_ms(5000);

	if((g_UartReceiveTemp <= 50) || (g_UartReceiveTemp == MACHINE_STOP))
	{
		State =  NORMAL_STATE;
		Buzzer_off();
		Servo_SetPostion(Position_0);
		_delay_ms(SERRVO_PERIOD_MS);
		Servo_Off();
	}
	else
	{
		/*Do nothing*/
	}

}






void init(void)
{
	/*Enable Global Interrupts */
	SREG |= (1<<7);

	/* Initialize the UART driver with Baud-rate = 9600 bits/sec */
	UART_init(9600);
	UartReceive_setCallBack(UartReceiveMessage);

	/* initialize ADC driver */
	ADC_ConfigType adcConfig = {ADC_REF_VOLT_CODE, F_CPU_8};
	ADC_init(&adcConfig);

	/* initialize EEPROM driver*/
	Servo_init();

	/* initialize DcMotor driver*/
	DcMotor_Init();

	/* initialize Button driver*/
	Buzzer_init();
	Buzzer_off();

	/* initialize Leds*/
	GPIO_setupPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_OUTPUT);


}
