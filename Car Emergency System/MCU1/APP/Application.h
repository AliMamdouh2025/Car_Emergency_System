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

#ifndef APPLICATION_H_
#define APPLICATION_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*States*/
#define ADDRESS_STATE 0
#define NORMAL_STATE 0
#define EMERGENCY_STATE 1
#define ABNORMAL_STATE 2

/*Led states*/
#define GREEN_STATE 0
#define YELLOW_STATE 1
#define RED_STATE 2

/*Machine states*/
#define MACHINE_STOP 155
#define ABNORMAL_UART 160

/*LM35*/
#define LM35_VOLTAGE_LIMIT 150





/*******************************************************************************
 *                      Global Variables                                       *
 *******************************************************************************/
boolean Button_Flag;
boolean Abnormal_Flag;
uint8 counter;





/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Timer_On(void(*a_ptr)(void));
void Emergency_Timer(void);
void LED(void);
void UartReceiveMessage(void);
void Machine_Stop(uint8 Temp);
void Normal_State(void);
void Emergency_State(void);
void Abnormal_State(void);
void init(void);
#endif /* APPLICATION_H_ */
