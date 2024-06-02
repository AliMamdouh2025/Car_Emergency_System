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



