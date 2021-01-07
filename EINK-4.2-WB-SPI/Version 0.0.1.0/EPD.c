#include "com.h"

unsigned char	HRES_byte1;
unsigned char	HRES_byte2;						
unsigned char	VRES_byte1;
unsigned char	VRES_byte2;

//unsigned char	temp_FULL[15000];
/*unsigned char	temp_64_80[162];
unsigned char	temp_176_80[162];
unsigned char	temp_288_80[162];
unsigned char	temp_32_128[872];
unsigned char	temp_96_128[872];
unsigned char	temp_112_128[218];
unsigned char	temp_176_128[872];
unsigned char	temp_240_128[872];
unsigned char	temp_304_128[872];
*/

/////////////////////////////////////partial screen update LUT///////////////////////////////////////////
xdata const unsigned char lut_vcom1[] ={
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00
	,0x00	,0x00,					};
xdata const unsigned char lut_ww1[] ={
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,};
xdata const unsigned char lut_bw1[] ={
0x80	,0x19	,0x01	,0x00	,0x00	,0x01,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
xdata const unsigned char lut_wb1[] ={
0x40	,0x19	,0x01	,0x00	,0x00	,0x01,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};
xdata const unsigned char lut_bb1[] ={
0x00	,0x19	,0x01	,0x00	,0x00	,0x01,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	
0x00	,0x00	,0x00	,0x00	,0x00	,0x00,	};

void EPD_ChkStatus(void)
{
		unsigned char busy;
		unsigned char	temp;
		do
		{
			temp	=	SpiWriteCommand	(0x71);
			busy	=	nBUSY;
			busy	=	!(busy & 0x01);
		}
		while(busy);   
		DELAY_mS(200);
}

void EPD_W21_Init(void)
{
		nBS		=	0;				//4 wire spi mode selected
		RES	=	0;				//module reset	
		DELAY_mS(1000);
		RES	=	1;
		DELAY_mS(1000);
}

void EPD_Refresh(void)
{
		SpiWriteCommand	(0x12);			//DISPLAY REFRESH 	
		DELAY_mS(100);	        //!!!The delay here is necessary, 200uS at least!!!     
		EPD_ChkStatus();
}

/////////////////////////////Enter deep sleep mode////////////////////////
void EPD_Sleep(void) //Enter deep sleep mode
{
		SpiWriteCommand	(0X50);
		SpiWriteData	(0xf7);	
		SpiWriteCommand	(0X02);  	//power off
		EPD_ChkStatus();
		SpiWriteCommand	(0X07);  	//deep sleep
		SpiWriteData	(0xA5);
}

///////////////////OTP/////////////////////////////////////////////////////////////////
void EPD_Init(void)
{
		HRES_byte1=0x01;			 						//400
		HRES_byte2=0x90;						
		VRES_byte1=0x01;									//300
		VRES_byte2=0x2c;
	
		EPD_W21_Init();
	
		SpiWriteCommand	(0x06);        	 //boost soft start
		SpiWriteData	(0x17);					//A
		SpiWriteData	(0x17);					//B
		SpiWriteData	(0x17);					//C       

		SpiWriteCommand	(0x04);  
		EPD_ChkStatus();

		SpiWriteCommand	(0x00);						//panel setting
		SpiWriteData	(0x1f);					//LUT from OTP£¬400x300

		SpiWriteCommand	(0x61);						//resolution setting
		SpiWriteData	(HRES_byte1);		//400
		SpiWriteData	(HRES_byte2);     	 
		SpiWriteData	(VRES_byte1);		//300
		SpiWriteData	(VRES_byte2);

		SpiWriteCommand(0X50);						//VCOM AND DATA INTERVAL SETTING			
		SpiWriteData(0x97);					//WBmode:VBDF 17|D7 VBDW 97 VBDB 57		WBRmode:VBDF F7 VBDW 77 VBDB 37  VBDR B7
}

/***************** full screen display picture*************************/
void EPD_Display_Clean(void)
{
		unsigned int i;
		SpiWriteCommand	(0x10);
		for(i=0;i<15000;i++)	     
		{
				SpiWriteData	(0xff);
		}  
		DELAY_mS(2);	
		
		SpiWriteCommand	(0x13);
		for(i=0;i<15000;i++)	     
		{
				SpiWriteData	(0xff);
		}  
		DELAY_mS(2);
}

void PIC_Display(const unsigned char* picData)
{
	unsigned int i;
	SpiWriteCommand	(0x10);	       //Transfer old data
	for(i=0;i<15000;i++)	     
		SpiWriteData	(0xff); 

	SpiWriteCommand	(0x13);		     //Transfer new data
	for(i=0;i<15000;i++)	     
	{
		SpiWriteData	(*picData);
		picData++;
	}
}

void PIC_Display_Partial(const unsigned char* picData)
{
	
	unsigned int i;
	unsigned int x_startH,x_startL,x_endH,x_endL,y_startH,y_startL,y_endH,y_endL;
	
	x_startH=10/256;
	x_startL=10%256;	
	
	x_endH=34/256; 
	x_endL=34%256-1; 	
	
	y_startH=10/256;
	y_startL=10%256;

	y_endH=46/256;
	y_endL=46%256-1;
	
	SpiWriteCommand	(0x91);							//This command makes the display enter partial mode
	SpiWriteCommand	(0x90);							//resolution setting
	
	SpiWriteData	(x_startH);   		//x-start     
	SpiWriteData	(x_startL);	  

	SpiWriteData	(x_endH);   			//x-end	  
	SpiWriteData	(x_endL);	  	

	SpiWriteData	(y_startH);				//y-start    
	SpiWriteData	(y_startL);   		

	SpiWriteData	(y_endH);					//y-end
	SpiWriteData	(y_endL);  

	SpiWriteData	(0x00);						//PT_SCAN
	

	SpiWriteCommand	(0x10);	       //Transfer old data
	for(i=0;i<872;i++)	     
		SpiWriteData	(0xff); 

	SpiWriteCommand	(0x13);		     //Transfer new data
	for(i=0;i<872;i++)	     
	{
		SpiWriteData	(*picData);
		picData++;
	}
}

