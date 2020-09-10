/****************************************************************************/
/* Auther	: yousif magdy												  	*/
/* Date		: 08 August 2020												*/
/* Version	: V01	 														*/
/****************************************************************************/


#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H
/*option 	RCC_HSE_CRYSTAL
			RCC_HSE_RC
			RCC_HSI
			RCC_PLL	*/
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL

/*OPTIONS:	RCC_PLL_IN_HSI_DIV2
			RCC_PLL_IN_HSE_DIV2
			RCC_PLL_IN_HSE	*/
/*NOTE: YOU HAVE TO CHOOSE IF RCC IS PLL*/
			
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT RCC_PLL_IN_HSE_DIV2
#endif
/*OPTIONS: 2: 16*/
/*NOTE: YOU HAVE TO CHOOSE IF RCC IS PLL*/
#define RCC_PLL_MUL_VAL 4

#endif
