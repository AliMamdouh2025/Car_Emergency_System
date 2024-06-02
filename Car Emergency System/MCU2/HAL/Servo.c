/*
 * Servo.c
 *
 *  Created on: Aug 30, 2023
 *      Author: lap
 */

#include <avr/io.h> /* To use SREG register */
#include <avr/interrupt.h>
#include <util/delay.h> ///delay
#include "common_macros.h"
#include "std_types.h" ///delay
#include "Servo.h" ///delay


void Servo_init(void)
{
	SET_BIT(DDRD,PD5); /* Make OC1A pin as output */
}

void Servo_SetPostion(Servo_Position_t Position)
{
	TCNT1 = 0;		/* Set timer1 initial count to zero */
	ICR1 = 2499;	/* Set TOP count for timer1 in ICR1 register */

	OCR1A = Position; /* Set the compare value */

	/* Configure timer control register TCCR1A
	 * 1. Clear OC1A on compare match (non inverting mode) COM1A1=1 COM1A0=0
	 * 2. Disconnect OC1B  COM1B0=0 COM1B1=0
	 * 3. FOC1A=0 FOC1B=0 because these bits are only active in case non-pwm mode
	 * 4. Fast Pwm Mode with the TOP in ICR1 WGM10=0 WGM11=1 (Mode Number 14)
	 */
	TCCR1A = (1<<WGM11) | (1<<COM1A1);

	/* Configure timer control register TCCR1B
	 * 1. Fast Pwm Mode with the TOP in ICR1 WGM12=1 WGM13=1 (Mode Number 14)
	 * 2. Prescaler = F_CPU/8
	 */
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS11);

}


void Servo_Off(void)
{
	TCNT1 = 0;
	ICR1 = 0;
	OCR1A = 0;
	TCCR1A = 0;
	TCCR1B = 0;

}
