/****************************************************************************/
/* Auther	: yousif magdy												  	*/
/* Date		: 29 JUL 2020													*/
/* Version	: V01	 														*/
/****************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

				/*BIT OPERATION*/
#define SETBIT(VAR,BIT) 			(VAR | =(1<<BIT))
#define CLRBIT(VAR,BIT)				(VAR & = ~(1<<BIT))
#define GETBIT(VAR,BIT) 			(VAR>>BIT)&1
#define TOGBIT(VAR,BIT) 			(VAR^=(1<<BIT))

				/*PORT OPERATION*/
#define SETPORT(VAR)   				(VAR=0xffffffff)
#define CLRPORT(VAR)				(VAR=0x00000000)
#define GETPORT(VAR) 				(VAR&0xffffffff)

#define SETPORT_LOW_NIPPLE(VAR)		(VAR|=0x0000ffff)
#define CLRPORT_LOW_NIPPLE(VAR) 	(VAR&=0xffff0000)
#define GETPORT_LOW_NIPPLE(VAR)		(VAR&0x0000ffff)

#define SETPORT_HIGH_NIPPLE(VAR)	(VAR|=0xffff0000)
#define CLRPORT_HIGH_NIPPLE(VAR)	(VAR&=0x0000ffff)
#define GETPORT_HIGH_NIPPLE(VAR)	((VAR&0x0000ffff)>>16)

#endif
