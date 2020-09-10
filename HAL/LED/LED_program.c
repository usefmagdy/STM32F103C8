/********************************************************************************/
/* Auther		: yousif magdy												  	*/
/* Date			: 13 AUG 2020													*/
/* Version		: V01	 														*/
/* Description  : Function Implementation										*/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BITMATH.h"
#include "GPIO_Interface.h"
void LED_OnVoid(u8 copy_u8Port,u8 copy_u8Pin)
{
	/*Options : OUTPUT_SPEED_2MHZ_PP
				OUTPUT_SPEED_10MHZ_PP
				OUTPUT_SPEED_50MHZ_PP*/
	MGPIO_VoidSetPinDirection(copy_u8Port,copy_u8Pin,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VoidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,HIGH);
	
}
void LED_OffVoid(u8 copy_u8Port,u8 copy_u8Pin)
{
	/*Options : OUTPUT_SPEED_2MHZ_PP
				OUTPUT_SPEED_10MHZ_PP
				OUTPUT_SPEED_50MHZ_PP*/
	MGPIO_VoidSetPinDirection(copy_u8Port,copy_u8Pin,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VoidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,LOW);
)
void LED_TogVoid(u8 copy_u8Port,u8 copy_u8Pin)
{
	/*Options : OUTPUT_SPEED_2MHZ_PP
				OUTPUT_SPEED_10MHZ_PP
				OUTPUT_SPEED_50MHZ_PP*/
	MGPIO_VoidSetPinDirection(copy_u8Port,copy_u8Pin,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VoidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,LOW);
	for(u16 i=0;i<5000;i++)
	{
		for(u16 j=0;j<5000;j++)
		{
			asm("NOP");
		}
	}
	MGPIO_VoidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,HIGH);	
}