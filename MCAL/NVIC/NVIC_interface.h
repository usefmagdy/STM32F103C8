/********************************************************************************/
/* Auther		: yousif magdy												  	*/
/* Date			: 14 AUG 2020													*/
/* Version		: V01	 														*/
/* Description  : Function prototype											*/
/********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(u8 copy_u8PerIndx,u8 copy_u8Priority);
void MNVIC_voidInit(void);

#define GROUP3 0x05FA0300 	// 4bits for Group
#define GROUP4 0x05FA0400	// 3bits for Group and 1bit for subpriorty
#define GROUP5 0x05FA0500	// 2bits for Group and 2bit for subpriorty
#define GROUP6 0x05FA0600	// 1bits for Group and 3bit for subpriorty
#define GROUP7 0x05FA0700	// 4bit for subpriorty
#endif