#include <STC15F2K60S2.H>
#include "com.h"

void SpiPortInit(unsigned char port)
{
    SPDAT = 0;
    SPSTAT = SPIF | WCOL;
	if(1	==	port)
	{
		P1M0	=	0x00;
		P1M1	=	0x00;
		SPCTL	=	0xD8;
		AUXR1	&=	0xf3;
	}
	else if(2	==	port)
	{
		P2M0	=	0x00;
		P2M1	=	0x00;
		SPCTL	=	0xD8;
		AUXR1	&=	0xf7;  
	}
	else if(3	==	port)
	{
		P4M0	=	0x00;
		P4M1	=	0x00;
		P5M0	=	0x00;
		P5M1	=	0x00;
		SPCTL	=	0xD8;
		AUXR1	&=	0xfb;
	}
}

unsigned char SpiWriteByte(unsigned char byte)
{
		nCS		=	0;
    SPDAT	=	byte;
    while (!(SPSTAT & SPIF));
    SPSTAT	=	SPIF | WCOL;
    nCS		=	1;
    
    return SPDAT;
}

unsigned char SpiWriteCommand(unsigned char INIT_COM)
{
	unsigned char	RET;
	nDC		=	0;
	RET	=	SpiWriteByte(INIT_COM);
	nDC		=	1;
	
	return RET;
}
void SpiWriteData(unsigned char INIT_DATA)
{
	nDC		=	1;
	SpiWriteByte(INIT_DATA);
	nDC		=	1;
}
