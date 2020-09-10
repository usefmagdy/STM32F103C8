/**************************************************************************/
/* Auther 	: yousif magdy
/* Date    	: 31 AUG 2020
/* Version	: V01
/**************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"
void HLEDMRX_voidInit(void)
{
	MGPIO_VoidSetPinDirection(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);
	
	
	
	MGPIO_VoidSetPinDirection(LEDMRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);
}
void HLEDMRX_voidDisplay(u8 *copy_u8Data)
{
	while(1)
	{
	/*Disable all colomns */
	DisableAllCols();
	SetRowsValues(copy_u8Data[0]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL0_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	
	DisableAllCols();
	SetRowsValues(copy_u8Data[1]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL1_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	
	DisableAllCols();
	SetRowsValues(copy_u8Data[2]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL2_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	
	DisableAllCols();
	SetRowsValues(copy_u8Data[3]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL3_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	
	DisableAllCols();
	SetRowsValues(copy_u8Data[4]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL4_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	
	DisableAllCols();
	SetRowsValues(copy_u8Data[5]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL5_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	
	DisableAllCols();
	SetRowsValues(copy_u8Data[6]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL6_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	
	DisableAllCols();
	SetRowsValues(copy_u8Data[7]);
	/*enable coloumn 0*/
	MGPIO_VoidSetPinValue(LEDMRX_COL7_PIN,LOW);
	MSTK_voidSetBusyWait(2500);
	}
}
static void DisableAllCols(void)
{
	MGPIO_VoidSetPinValue(LEDMRX_COL0_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL1_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL2_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL3_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL4_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL5_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL6_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL7_PIN,HIGH);
	
}
static void SetRowsValues(u8 copy_u8Value)
{
	u8 Local_u8Bit=0;
	Local_u8Bit=GETBIT(copy_u8Value,0);
	MGPIO_VoidSetPinValue(LEDMRX_ROW0_PIN,Local_u8Bit);
	
	Local_u8Bit=GETBIT(copy_u8Value,1);
	MGPIO_VoidSetPinValue(LEDMRX_ROW1_PIN,Local_u8Bit);
	
	Local_u8Bit=GETBIT(copy_u8Value,2);
	MGPIO_VoidSetPinValue(LEDMRX_ROW2_PIN,Local_u8Bit);
	
	Local_u8Bit=GETBIT(copy_u8Value,3);
	MGPIO_VoidSetPinValue(LEDMRX_ROW3_PIN,Local_u8Bit);
	
	Local_u8Bit=GETBIT(copy_u8Value,4);
	MGPIO_VoidSetPinValue(LEDMRX_ROW4_PIN,Local_u8Bit);
	
	Local_u8Bit=GETBIT(copy_u8Value,5);
	MGPIO_VoidSetPinValue(LEDMRX_ROW5_PIN,Local_u8Bit);
	
	Local_u8Bit=GETBIT(copy_u8Value,6);
	MGPIO_VoidSetPinValue(LEDMRX_ROW6_PIN,Local_u8Bit);
	
	Local_u8Bit=GETBIT(copy_u8Value,7);
	MGPIO_VoidSetPinValue(LEDMRX_ROW7_PIN,Local_u8Bit);
}
