
/************************************************/																													/*****************************************/
/* Author  :  yousif magdy          	      	*/
/* Version :  V01                       	 	*/
/* Date    :  5 Sep 2020     		         	*/
/************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_CreateTask(u8 copy_u8ID,u16 copy_u16Periodicity, void (*ptr) (void),u16 copy_u16FirstDelay);
void SOS_Strat(void);
#endif