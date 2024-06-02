/*
 * button.h
 *
 *  Created on: Aug 30, 2023
 *      Author: lap
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#define BUTTON_PORT DDRB
#define BUTTON_PIN PB2
#define BUTTON_EDGE_TYPE ISC2
#define BUTTON_INTERRUPT_ID INT2
#define BUTTON_ISR INT2_vect

/* Global variables to hold the address of the call back function in the application *//////////////#if interrupt
static volatile void (*g_callBackPtrReceive)(void);


void Button_Init(void);

#endif /* BUTTON_H_ */
