/********************************************************************************/
/* Auther		: yousif magdy												  	*/
/* Date			: 14 AUG 2020													*/
/* Version		: V01	 														*/
/* Description  : Function Implementation										*/
/********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_Interface.h"
void SevenSegmentInitVoid(u8 copy_u8Port)
{
	MGPIO_VoidSetPortDirection(copy_u8Port,Mode);		
}
void SevenSegmentDisplayVoid(u8 copy_u8ModeSeven,u8 copy_u8NumDis,u8 copy_u8Nipple,u8 copy_u8Port)
{
	u8 DisNum[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x3D,0x07,0x7F,0x6F};//{0,1,2,3,4,5,6,7,8,9}
	switch(copy_u8Nipple)
	{
		case LOW_NIPPLE:
			switch(copy_u8ModeSeven)
			{
				case COMMON_CATHODE:
				MGPIO_VoidSetPortValue(copy_u8Port,DisNum[copy_u8NumDis]);
				break;
				case COMMON_ANODE:
				MGPIO_VoidSetPortValue(copy_u8Port,~(DisNum[copy_u8NumDis]));
				break;
				default:break;
			}
		break;
			case HIGH_NIPPLE:
			switch(copy_u8ModeSeven)
			{
				case COMMON_CATHODE:
				MGPIO_VoidSetPortValue(copy_u8Port,(DisNum[copy_u8NumDis])<<8);
				break;
				case COMMON_ANODE:
				MGPIO_VoidSetPortValue(copy_u8Port,(~(DisNum[copy_u8NumDis]))<<8);
				break;
				default:break;
			}
		break;
			default:break;
	}	
}

