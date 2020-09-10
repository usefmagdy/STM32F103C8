/********************************************************************************/
/* Auther		: yousif magdy												  	*/
/* Date			: 12 AUG 2020													*/
/* Version		: V01															*/
/* Despription	: Function Implementation										*/
/********************************************************************************/

#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"


void MGPIO_VoidSetPinDirection(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Mode)
{
	switch (copy_u8Port)
	{
		case GPIOA:
			if (copy_u8Pin<=7)
			{
			GPIOA_CRL &=~((0b1111)<<(copy_u8Pin*4)); 
			GPIOA_CRL |=((copy_u8Mode)<<(copy_u8Pin*4));
			}
			else if (copy_u8Pin<=15)
			{
			copy_u8Pin=copy_u8Pin-8;
			GPIOA_CRH &=~((0b1111)<<(copy_u8Pin*4)); 
			GPIOA_CRH |=((copy_u8Mode)<<(copy_u8Pin*4));
			}
		break;
		case GPIOB:
			if (copy_u8Pin<=7)
			{
			GPIOB_CRL &=~((0b1111)<<(copy_u8Pin*4)); 
			GPIOB_CRL |=((copy_u8Mode)<<(copy_u8Pin*4));
			}
			else if (copy_u8Pin<=15)
			{
			copy_u8Pin=copy_u8Pin-8;
			GPIOB_CRH &=~((0b1111)<<(copy_u8Pin*4)); 
			GPIOB_CRH |=((copy_u8Mode)<<(copy_u8Pin*4));
			}
		break;
		case GPIOC:
		if (copy_u8Pin<=7)
			{
			GPIOC_CRL &=~((0b1111)<<(copy_u8Pin*4)); 
			GPIOC_CRL |=((copy_u8Mode)<<(copy_u8Pin*4));
			}
			else if (copy_u8Pin<=15)
			{
			copy_u8Pin=copy_u8Pin-8;
			GPIOC_CRH &=~((0b1111)<<(copy_u8Pin*4)); 
			GPIOC_CRH |=((copy_u8Mode)<<(copy_u8Pin*4));
			}
		break;
		default: break;
	}
}
void MGPIO_VoidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value)
{
	switch (copy_u8Port)
	{
		case GPIOA:
			if (copy_u8Value== HIGH)
			{
			SETBIT(GPIOA_ODR,copy_u8Pin);
			}
			else if (copy_u8Value== LOW)
			{
			CLRBIT(GPIOA_ODR,copy_u8Pin);
			}
		break;
		case GPIOB:
			if (copy_u8Value== HIGH)
			{
			SETBIT(GPIOB_ODR,copy_u8Pin);
			}
			else if (copy_u8Value== LOW)
			{
			CLRBIT(GPIOB_ODR,copy_u8Pin);
			}
		break;
		case GPIOC:
		if (copy_u8Value== HIGH)
			{
			SETBIT(GPIOC_ODR,copy_u8Pin);
			}
			else if (copy_u8Value== LOW)
			{
			CLRBIT(GPIOC_ODR,copy_u8Pin);
			}
		break;
		default: break;
	}

}
u8 MGPIO_VoidGetPinValue(u8 copy_u8Port,u8 copy_u8Pin)
{
	u8 Loc_Result=0;
	switch (copy_u8Port)
	{
		case GPIOA:
			Loc_Result=GETBIT(GPIOA_IDR,copy_u8Pin);
		break;
		case GPIOB:
			Loc_Result=GETBIT(GPIOB_IDR,copy_u8Pin);
		break;
		case GPIOC:
		Loc_Result=GETBIT(GPIOC_IDR,copy_u8Pin);
		break;
		default: break;
	}
	return Loc_Result;
}

void MGPIO_VoidSetPortDirection(u8 copy_u8Port,u32 copy_32Mode)
{
	switch (copy_u8Port)
	{
		case GPIOA:
			CLRPORT(GPIOA_CRL);
			CLRPORT(GPIOA_CRH);
			GPIOA_CRL =(copy_32Mode); 
			GPIOA_CRH =(copy_32Mode);
		break;
		case GPIOB:
			CLRPORT(GPIOB_CRL);
			CLRPORT(GPIOB_CRH);
			GPIOB_CRL =(copy_32Mode); 
			GPIOB_CRH =(copy_32Mode);
		break;
		case GPIOC:
			CLRPORT(GPIOC_CRL);
			CLRPORT(GPIOC_CRH);
			GPIOC_CRL =(copy_32Mode); 
			GPIOC_CRH =(copy_32Mode);
		break;
		default: break;
	}
}

void MGPIO_VoidSetPortValue(u8 copy_u8Port,u8 copy_u8Value)
{
	switch (copy_u8Port)
	{
		case GPIOA:
			GPIOA_ODR=copy_u8Value;
		break;
		case GPIOB:
			GPIOB_ODR=copy_u8Value;
		break;
		case GPIOC:
			GPIOC_ODR=copy_u8Value;
		break;
		default: break;
	}

}
u32 MGPIO_VoidGetPortValue(u8 copy_u8Port)
{
	u32 Loc_Result=0;
	switch (copy_u8Port)
	{
		case GPIOA:
			Loc_Result=GETPORT_LOW_NIPPLE(GPIOA_IDR);
		break;
		case GPIOB:
			Loc_Result=GETPORT_LOW_NIPPLE(GPIOB_IDR);
		break;
		case GPIOC:
		Loc_Result=GETPORT_LOW_NIPPLE(GPIOC_IDR);
		break;
		default: break;
	}
	return Loc_Result;
}


