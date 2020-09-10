/************************************************/																													/*****************************************/
/* Author  :  yousif magdy          	      	*/
/* Version :  V01                       	 	*/
/* Date    :  5 Sep 2020     		         	*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

void SOS_CreateTask(u8 copy_u8ID,u16 copy_u16Periodicity, void (*ptr) (void),u16 copy_u16FirstDelay)
{
	OS_TASKS[copy_u8ID].Periodicity=copy_u16Periodicity;
	OS_TASKS[copy_u8ID].Fptr=ptr;
	OS_TASKS[copy_u8ID].FirstDelay=copy_u16FirstDelay;
	
}
void SOS_voidStart(void)
{
	/*Initization */
	MSTK_Init();
	/*1msec for tick*/
	/*HSE =AHB/8 =1MHZ =====> 1000 Micro sec ======> 1msec */
	MSTK_voidSetIntervalPeriodic(1000,Schedular);

	
}
void SOS_KillTask(u8 copy_u8ID)
{
	for (u8 i=copy_u8ID-1;i<NUMBER_TASK-1;i++)
	{
	OS_TASKS[i].Periodicity=OS_TASKS[i+1].Periodicity;
	OS_TASKS[i].Fptr=OS_TASKS[i+1].Fptr;
	OS_TASKS[i].First_Delay=OS_TASKS[i+1].First_Delay;
	OS_TASKS[i].State=OS_TASKS[i+1].State;
	}

}
void ResumeTask(u8 copy_u8ID)
{
	OS_TASKS[copy_u8ID].State=READY;
}
void SespendTask(u8 copy_u8ID)
{
	OS_TASKS[copy_u8ID].State=SESPEND;
}