


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
/*line and mode */

static void (*EXTI0_Callback)(void)=NULL;
void MEXTI_voidInit()
{
/*	#if EXTI_LINE == LINE0
	SETBIT(EXTI->IMR,LINE0);
	#elif EXTI_LINE == LINE1
	SETBIT(EXTI->IMR,LINE1);
	#elif EXTI_LINE == LINE2
	SETBIT(EXTI->IMR,LINE2);
	#elif EXTI_LINE == LINE3
	SETBIT(EXTI->IMR,LINE1);
	#else #error "Wrong Line"
*/
	
	
	#if EXTI_SENSE_MODE == RISING
	SETBIT(EXTI->RTSR,EXTI_LINE);
	#elif EXTI_SENSE_MODE == FALLING
	SETBIT(EXTI->FTSR,EXTI_LINE);
	#elif EXTI_SENSE_MODE == ONCH
	SETBIT(EXTI->RTSR,EXTI_LINE);
	SETBIT(EXTI->FTSR,EXTI_LINE);
	#else #error "Wrong line and mode"
	/*Disable interrupt*/
	CLRBIT(EXTI->IMR,EXTI_LINE);
}
void MEXTI_voidEnableEXTI(u8 copy_u8Line)
{
	SETBIT(EXTI->IMR,copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 copy_u8Line)
{
	CLRBIT(EXTI->IMR,copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 copy_u8Line)
{
	SETBIT(EXTI->SWIER,copy_u8Line);
}
void MEXTI_voidSetSignalLatch(u8 copy_u8Line,u8 copy_u8Mode)
{
	switch (copy_u8Mode)
	{
		case RISING:	SETBIT(EXTI->RTSR,EXTI_LINE); break;
		case FALLING:	SETBIT(EXTI->FTSR,EXTI_LINE);break;
		case ONCH:		SETBIT(EXTI->RTSR,EXTI_LINE);
						SETBIT(EXTI->FTSR,EXTI_LINE); break;
		
	}
	SETBIT(EXTI->IMR,copy_u8Line);
}
void EXTI0_IRQHandler(void)
{
	
	EXTI0_Callback();//ahmed();
	SETBIT(EXTI->PR,0);
	
}
void MEXTI_voidSetCallback( (void (*ptr)(void)	) 
{
	EXTI0_Callback=ptr;
}
