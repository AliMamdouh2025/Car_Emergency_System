/******************************************************************************
 *
 * Module: Application
 *
 * File Name: Application.h
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
#include "Internal_EEPROM_interface.h"
#include "std_types.h"
#include <avr/eeprom.h>
#include "adc.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "pwm.h"
#include "button.h"
#include "WatchDog.h"
#include "timer1.h"
#include "Application.h"


/*******************************************************************************
 *                     initialize Global Variables                             *
 *******************************************************************************/
boolean Button_Flag = 0;
boolean Abnormal_Flag = 0;
uint8 counter = 0;



/*******************************************************************************
 *                      Functions implementation                                  *
 *******************************************************************************/

void Timer_On(void(*a_ptr)(void))
{
	Timer1_ConfigType Config_Timer;
	Config_Timer.prescaler = F_CPU_1024CLK;
	Config_Timer.mode = compare;
	Config_Timer.initial_value = 1;
	Config_Timer.compare_value = 515;
	Timer1_init(&Config_Timer);
	Timer1_setCallBack(a_ptr);
}







void Emergency_Timer(void)
{
	counter++;
	if(counter == 14)
	{
		counter = 0;
		Abnormal_Flag = 1;
	}
	else
	{
		/*Do nothing*/
	}

}




void LED(void)
{
	Button_Flag = 1;
}

void UartReceiveMessage(void)
{

}



void Machine_Stop(uint8 Temp)
{
	if(Button_Flag == 1)
	{
		UART_sendByte(MACHINE_STOP);
	}
	else
	{
		UART_sendByte(Temp);
	}

}


void Normal_State(void)
{
	/*Create Temp which holds temperature value */
	uint8 Temp = LM35_getTemperature();

	/* Display the temperature value every time at same position */
	if(Temp < 20)
	{
		DcMotor_Rotate(STOP,0);
		UART_sendByte(Temp);
		Button_Flag = 0;
	}
	else if(Temp < 40)
	{
		DcMotor_Rotate(CW,(Temp*5)/2);
		UART_sendByte(Temp);
		Button_Flag = 0;
	}
	else if(Temp <= 50)
	{
		DcMotor_Rotate(CW,100);
		Machine_Stop(Temp);
	}
	else if(Temp <= LM35_VOLTAGE_LIMIT)
	{
		EEPROM_write(ADDRESS_STATE, EMERGENCY_STATE);
		UART_sendByte(Temp);
		counter = 0;
		Timer_On(Emergency_Timer);
	}
	else
	{
		/*Do nothing*/
	}

}





void Emergency_State(void)
{
	/*Create Temp which holds temperature value */
	uint8 Temp = LM35_getTemperature();

	/* Display the temperature value every time at same position */
	if(Temp <= 50)
	{
		EEPROM_write(ADDRESS_STATE, NORMAL_STATE);
		Timer1_deInit();
		UART_sendByte(Temp);
		Abnormal_Flag = 0;
	}
	else if(Temp <= LM35_VOLTAGE_LIMIT)
	{
		/*Select Abnormal state*/
		if(Abnormal_Flag == 1)
		{
			EEPROM_write(ADDRESS_STATE, ABNORMAL_STATE);
			Abnormal_Flag = 0;
			Timer1_deInit();
			UART_sendByte(ABNORMAL_UART);
		}
		else
		{
			/*Send Temperature*/
			UART_sendByte(Temp);
		}
	}
	else
	{
		/*Do nothing*/
	}


}





void Abnormal_State(void)
{
	uint8 Temp = LM35_getTemperature();

	if((Temp <= 50) || (Temp == MACHINE_STOP))
	{
		EEPROM_write(ADDRESS_STATE, NORMAL_STATE);
		UART_sendByte(Temp);
	}
	else
	{
		WDT_ON(WDT_16ms);
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
	Internal_EEPROM_init();
	EEPROM_write(ADDRESS_STATE, NORMAL_STATE);

	/* initialize DcMotor driver*/
	DcMotor_Init();

	/* initialize Button driver*/
	Button_Init();
	Button_setCallBack(LED);
}

