#include "com.h"

unsigned char temp;
void main()
{
		xdata	unsigned char men[15000];
		unsigned long	i;
		P0M0	=	0;
		P0M1	=	0;
		P1M0	=	0;
		P1M1	=	0;
		P2M0	=	0;
		P2M1	=	0;
	
		
		SystemInit();
	
//		EPD_Initial_value(0xff);				//Initial value of old data				

		EPD_Init(); 										//EPD init
		PIC_Display(gImage_2); 
		EPD_Refresh();									//EPD_refresh		
		EPD_Sleep();										//EPD_sleep		
		//DELAY_S(20);		
		
//		EPD_Init(); 										//EPD init
	//	PIC_Display(gImage_basemap); 
 //   EPD_Refresh();									//EPD_refresh		
//		EPD_Sleep();										//EPD_sleep	
	

	while(1)
	{
		DELAY_S(5);
		for(i = 0; i < 15000; i++)men[i]	=	0;
		EPD_Init(); 										//EPD init
		//PIC_Display_Partial(gImage_num0);
		PIC_Display(men); 
		EPD_Refresh();									//EPD_refresh		
		EPD_Sleep();										//EPD_sleep		
		//DELAY_S(20);
		
	
	}	
}

