/*
 * WatchDog.c
 *
 *  Created on: Aug 31, 2023
 *      Author: lap
 */

#include <avr/io.h>
#include <util/delay.h>
#include "WatchDog.h"

//	function to enable Watchdog timer.
void WDT_ON(WDT_Time_t WDTime)
{
	// Watchdog timer enables with timeout period 2.1 second.
	WDTCR = (1<<WDE) | (WDTime);
}

// 	function to disable Watchdog timer.
void WDT_OFF(void)
{
	// Set the WDTOE & WDE bits in the same operation
	WDTCR = (1<<WDTOE)|(1<<WDE);
	// Wait 4 cycles before clear the WDE bit
	_delay_us(4);
	WDTCR = 0x00;
}

