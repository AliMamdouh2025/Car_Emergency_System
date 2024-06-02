/*
 * Servo.h
 *
 *  Created on: Aug 30, 2023
 *      Author: lap
 */

#ifndef SERVO_H_
#define SERVO_H_

#define SERVO_PORT PORTD
#define SERVO_PIN PD5
#define SERRVO_PERIOD_MS 20
#define STABILITY_FACTOR SERRVO_PERIOD_MS*35

typedef enum
{
	Position_0 = 124, Position_90 = 187, Position_180 = 250
}Servo_Position_t;


void Servo_init(void);
void Servo_SetPostion(Servo_Position_t Position);
void Servo_Off(void);

#endif /* SERVO_H_ */
