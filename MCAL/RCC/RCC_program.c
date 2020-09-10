/****************************************************************************/
/* Auther	: yousif magdy												  	*/
/* Date		: 08 August 2020												*/
/* Version	: V01	 														*/
/****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidEnableClock(u8 copyu8BusId,u8 copyu8PerId)
{
	if (copyu8PerId<=31)
	{
		switch (copyu8BusId)
		{
			case RCC_AHB  :	SETBIT(RCC_AHBENR  ,copyu8PerId); 	break;
			case RCC_APB1 :	SETBIT(RCC_APB1ENR ,copyu8PerId);	break;
			case RCC_APB2 :	SETBIT(RCC_APB2ENR ,copyu8PerId); 	break;
			//default 	  :/*return error*/ break;
		}
	}
	else
	{
		/*return Error*/
	}
}
void RCC_voidDisableClock(u8 copyu8BusId,u8 copyu8PerId)
{
	if (copyu8PerId<=31)
	{
		switch (copyu8BusId)
		{
			case RCC_AHB  :	CLRBIT(RCC_AHBENR  ,copyu8PerId); 	break;
			case RCC_APB1 :	CLRBIT(RCC_APB1ENR ,copyu8PerId);	break;
			case RCC_APB2 :	CLRBIT(RCC_APB2ENR ,copyu8PerId); 	break;
			//default 	  :/*return error*/ break;
		}
	}
	else
	{
		/*return Error*/
	}
}
void RCC_VoidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == 	RCC_HSE_CRYSTAL
	RCC_CR |=	(1<<16);/*RCC_CR=0x00010000 */
	RCC_CR &=  ~(1<<18);/*enbale HSI without bypass */
	RCC_CFGR= 0x00000001;
	#elif RCC_CLOCK_TYPE == 	RCC_HSE_RC
	RCC_CR |	=	(1<<16)|(1<<18);/*RCC_CR=0x00050000  enbale HSI with bypass */
	RCC_CFGR= 0x00000001;
	#elif RCC_CLOCK_TYPE == 	RCC_HSI
	RCC_CR |	=	(1<<0);/*enable HSI RCC_CR =0x00000081 with defualt triming*/
	RCC_CFGR= 0x00000000;
	#elif RCC_CLOCK_TYPE == 	RCC_PLL
		RCC_CFGR|=(1<<1);
		RCC_CFGR&=~(1<<0);
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV2
		RCC_CFGR|=17<<RCC_PLL_MUL_VAL;
		RCC_CR|=1<<24;
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV2
		
		
		RCC_CR|=1<<24;
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif 
	#endif
	
}
