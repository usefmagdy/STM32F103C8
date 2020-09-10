/********************************************************************************/
/* Auther		: yousif magdy												  	*/
/* Date			: 14 AUG 2020													*/
/* Version		: V01	 														*/
/* Description  : Function prototype											*/
/********************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_ISER0       *((u32*)0xE000E100) /* Enable External interrupts from 0  to 31 */
#define NVIC_ISER1       *((u32*)0xE000E104) /* Enable External interrupts from 32 to 63 */

#define NVIC_ICER0       *((u32*)0xE000E180)
#define NVIC_ICER1       *((u32*)0xE000E184)

#define NVIC_ISPR0       *((u32*)0xE000E200)
#define NVIC_ISPR1       *((u32*)0xE000E204)

#define NVIC_ICPR0       *((u32*)0xE000E280)
#define NVIC_ICPR1       *((u32*)0xE000E284)

#define NVIC_IABR0       *((volatile u32*)0xE000E300)
#define NVIC_IABR1       *((volatile u32*)0xE000E304)
/*					without Dereference								*/
#define NVIC_IPR		  ((volatile u8 *)0xE000E400)



/* in (SCB => AIRCR) 4 bits for group and 0 sub => 4bits in (IPR) to determine group number	*/
#define		GROUP4_SUB0		0x05FA0300
/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define		GROUP3_SUB1		0x05FA0400
/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define		GROUP2_SUB2		0x05FA0500
/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define		GROUP1_SUB3		0x05FA0600
/* in (SCB => AIRCR) 0 group for 4 bits for sub												*/
#define		GROUP0_SUB7		0x05FA0700

#endif