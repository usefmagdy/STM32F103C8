#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*line and mode */
void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 copy_u8Line);
void MEXTI_voidDisableEXTI(u8 copy_u8Line);
void MEXTI_voidSwTrigger(u8 copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 copy_u8Line,u8 copy_u8EXTISense);
void MEXTI_voidSetCallback( (void (*ptr)void) );

#endif