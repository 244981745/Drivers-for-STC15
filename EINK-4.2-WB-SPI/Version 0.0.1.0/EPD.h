#ifndef	_EPD_H
#define	_EPD_H

#include "com.h"

#define POS		1			//ÕýÏÔ
#define NEG		2			//¸ºÏÔ
#define CLEAR	3			//Çå³ý

#define	u16	(unsigned short)

extern	unsigned char	HRES_byte1;
extern	unsigned char	HRES_byte2;
extern	unsigned char	VRES_byte1;
extern	unsigned char	VRES_byte2;

/*
extern	unsigned char	temp_FULL[15000];
extern	unsigned char	temp_64_80[162];
extern	unsigned char	temp_176_80[162];
extern	unsigned char	temp_288_80[162];
extern	unsigned char	temp_32_128[872];
extern	unsigned char	temp_96_128[872];
extern	unsigned char	temp_112_128[218];
extern	unsigned char	temp_176_128[872];
extern	unsigned char	temp_240_128[872];
extern	unsigned char	temp_304_128[872];
*/

void EPD_ChkStatus(void);
void EPD_W21_Init(void);
void EPD_Refresh(void);
void EPD_Sleep(void);
void EPD_Init(void);
void EPD_Display_Clean(void);
void PIC_Display(const unsigned char* picData);
void PIC_Display_Partial(const unsigned char* picData);
void EPD_Lut1(void);
void EPD_Init_Partial(void);
void EPD_Initial_Value(unsigned char datas);

#endif
