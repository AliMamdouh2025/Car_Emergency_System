/******************************************************************************
 *
 * Module: main
 *
 * File Name: main.c
 *
 * Description: main file
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





int main(void)
{
	/* initialization of project*/
	init();
	uint8 State;


	while(1)
	{
		/*Reading state of project*/
		State = EEPROM_read(ADDRESS_STATE);

		switch (State)
		{
		case NORMAL_STATE:
			Normal_State();
			break;

		case EMERGENCY_STATE:
			Emergency_State();
			break;

		case ABNORMAL_STATE:
			Abnormal_State();
			break;
		}
	}
}



