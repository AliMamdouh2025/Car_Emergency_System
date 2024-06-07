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

	/* initialization of system*/
	init();

	while(1)
	{
		/*Selecting state of system*/
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


