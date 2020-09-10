#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H



typedef struct{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
	
}AFIO_t;
#endif
