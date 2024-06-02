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
#define NORMAL_STATE 0
#define EMERGENCY_STATE 1
#define ABNORMAL_STATE 2

/*Led states*/
#define GREEN_LED_PORT PORTA_ID
#define GREEN_LED_PIN PIN3_ID
#define YELLOW_LED_PORT PORTA_ID
#define YELLOW_LED_PIN PIN2_ID
#define RED_LED_PORT PORTA_ID
#define RED_LED_PIN PIN1_ID

/*Machine states*/
#define MACHINE_STOP 155
#define ABNORMAL_UART 160

/*LM35*/
#define LM35_VOLTAGE_LIMIT 150





/*******************************************************************************
 *                      Global Variables                                       *
 *******************************************************************************/
/*Flags global variables*/
boolean Stop_Machine_Flag;

/*Callback global variables*/
uint8 g_UartReceiveTemp;

/*State global variable*/
uint8 State;





/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Machine(void);
void UartReceiveMessage(void);
void Normal_State(void);
void Emergency_State(void);
void Abnormal_State(void);
void init(void);









#endif /* APPLICATION_H_ */
