#include <intrins.h>
void DELAY_nS(unsigned int delaytime)   // 1ns 
{
	unsigned short i;
	for(i = 0; i < delaytime; i++)
	{
		_nop_();
		_nop_();
	}
}

void DELAY_mS(unsigned int delaytime)    	// 1ms
{
	unsigned short i,k;
	for(k=0;k<delaytime;k++)
	{ 
		_nop_();
		_nop_();
		i = 2000;
		while (--i);
	} 
}
void DELAY_S(unsigned int delaytime)     //  1s
{
	unsigned char i, j, k,l;
	for(l = 0; l < delaytime; l ++)
	{
		for(i = 0; i < 92; i++)
			for(j = 0; j < 50; j++)
				for(k = 0; k < 238; k++)
					_nop_();
	}
}