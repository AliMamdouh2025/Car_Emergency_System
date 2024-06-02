/*
 * Potentiometer.c
 *
 *  Created on: Aug 30, 2023
 *      Author: lap
 */

#include "Potentiometer.h"
#include <avr/io.h> /* To use SREG register */
#include <avr/interrupt.h>
#include <util/delay.h> ///delay
#include "common_macros.h"
#include "std_types.h" ///delay
#include "adc.h" ///delay


Volt_Percent_t Voltage_Percent(void)
{
	uint16 Value = ADC_readChannel(POTENTIOMETER_CHANNEL);

	if(Value <= 102)
	{
		return Volt_10_Percent;
	}
	else if(Value <= 204)
	{
		return Volt_20_Percent;
	}
	else if(Value <= 306)
	{
		return Volt_30_Percent;
	}
	else if(Value <= 408)
	{
		return Volt_40_Percent;
	}
	else if(Value <= 510)
	{
		return Volt_50_Percent;
	}
	else if(Value <= 612)
	{
		return Volt_60_Percent;
	}
	else if(Value <= 714)
	{
		return Volt_70_Percent;
	}
	else if(Value <= 816)
	{
		return Volt_80_Percent;
	}
	else if(Value <= 918)
	{
		return Volt_90_Percent;
	}
	else
	{
		return Volt_100_Percent;
	}

}
