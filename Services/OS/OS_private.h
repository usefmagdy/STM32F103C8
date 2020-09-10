#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H
#define NULL        (void*)0
static TASK OS_TASKS[NUMBER_TASKS]={NULL};     /*ARRAY of Structures*/
typedef struct{
	u16 Periodicity;
	void (*Fptr)(void);
	u16 First_Delay;
	u8 State;
}TASK;

enum Task_State{READY,RUNING,SESPEND,WAITING};
/*volatile u16 Tick_Counter=0;
static void Schedular(void)
{
	for (u8 i=0;i<NUMBER_TASKS ; i++)
	{
		if (Tick_Counter % OS_TASKS[i].Periodicity ==0)
		{
			OS_TASKS[i].Fptr();
		}
		
	}
	Tick_Counter++;
}*/
static void Schedular(void)
{
	for (u8 i=0;i<NUMBER_TASKS ; i++)
	{
		if ((OS_TASKS[i].State ==READY) && (OS_TASKS[i].Fptr != NULL))
		{
			OS_TASKS[i].Fptr();
			OS_TASKS[i].FirstDelay=OS_TASKS[i].Periodicity[i]-1;
		}	
	}
	else
	{
		OS_TASKS[i].FirstDelay--;
	}
	Tick_Counter++;
}	
