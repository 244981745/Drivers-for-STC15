#ifndef	_COM_H
#define	_COM_H
#include <STC15F2K60S2.H>
#include "delay.h"
#include "spi.h"
#include "EPD.h"

#define SPIF        0x80        //SPSTAT.7
#define WCOL        0x40        //SPSTAT.6
#define SSIG        0x80        //SPCTL.7
#define SPEN        0x40        //SPCTL.6
#define DORD        0x20        //SPCTL.5

sbit	nDC		=	P1^0;
sbit	RES		=	P1^1;
sbit	nCS		=	P1^2;
sbit	SDI		=	P1^3;
sbit	SCLK	=	P1^5;
sbit	nBUSY	=	P1^6;
sbit	nBS		=	P1^7;
sbit	nRST	=	P2^7;

//extern	code const unsigned char gImage_basemap[15000];
extern	code const unsigned char gImage_2[15000];

extern	code const unsigned char gImage_num0[872];
extern	code const unsigned char gImage_num1[872];
extern	code const unsigned char gImage_num2[872];
extern	code const unsigned char gImage_num3[872];
extern	code const unsigned char gImage_num4[872];
extern	code const unsigned char gImage_num5[872];
extern	code const unsigned char gImage_num6[872];
extern	code const unsigned char gImage_num7[872];
extern	code const unsigned char gImage_num8[872];
extern	code const unsigned char gImage_num9[872];
extern	code const unsigned char gImage_dot[218];


void SystemInit(void);



#endif
