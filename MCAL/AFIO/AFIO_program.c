

void MAFIO_voidSetEXTICONF(u8 copy_u8line,u8 copy_u8PortMap)
{
	u8 local_u8RegIndex=0;
	if(copy_u8line<=3)
	{
		local_u8RegIndex=0;
	}
	else if(copy_u8line<=7)
	{
		local_u8RegIndex=1;
		copy_u8line -=4;
	}
	else if(copy_u8line<=11)
	{
		local_u8RegIndex=2;
		copy_u8line -=8;
	}
	else if(copy_u8line<=15)
	{
		local_u8RegIndex=3;
		copy_u8line -=12;
	}
	AFIO->EXTICR[local_u8RegIndex] &=~((0b1111)<<(copy_u8line*4));
	AFIO->EXTICR[local_u8RegIndex]|=((copy_u8PortMap)<<(copy_u8line*4));
	
}