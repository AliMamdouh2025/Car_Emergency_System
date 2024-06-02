 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: header file for the motor driver
 *
 * Author: Ali Mamdouh
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PORT_MOTOR PORTB_ID
#define PINCW_MOTOR PIN0_ID //when it is 1 and the other pin PINACW_MOTOR is 0 motor rotate CW
#define PINACW_MOTOR PIN1_ID//when it is 1 and the other pin PINCW_MOTOR is 0 motor rotate ACW
#define PINENABLE_MOTOR PIN3_ID //Pin enable of motor where we put PWM in it

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	CW, A_CW, STOP
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description : Function to initialize the Motor driver
 * 1- Set the two pins of motor which are responsible for ClockWise,AntiClockWise,Stop the motor
 */
void DcMotor_Init(void);

/*
 * Description : Function to control the speed and rotation direction of the motor
 * 1-speed is controlled by PWM driver which sends signals to the enable pin of motor
 * 2-rotation is controlled by the two pins of the H-Bridge of the motor
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_H_ */
