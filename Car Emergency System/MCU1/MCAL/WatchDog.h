/*
 * Watch_dog.h
 *
 *  Created on: Aug 31, 2023
 *      Author: lap
 */

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

typedef enum
{
	WDT_16ms, WDT_32ms, WDT_64ms, WDT_128ms, WDT_256ms, WDT_512ms, WDT_1024ms, WDT_2048ms
}WDT_Time_t;


void WDT_ON(WDT_Time_t WDTime);
void WDT_OFF(void);




#endif /* WATCHDOG_H_ */
