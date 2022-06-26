#line 1 "..\\code\\OV7670\\delay.c"

#line 1 "..\\code\\OV7670\\delay.h"




void OV7670_delay_us(unsigned int time);
void OV7670_delay_ms(unsigned int time);




#line 3 "..\\code\\OV7670\\delay.c"

void OV7670_delay_us(unsigned int i)
 {     
    while( i--);
 }		  
 

void OV7670_delay_ms(unsigned int time)
	 {
	  while(time--)
	  	  {	
		   OV7670_delay_us(1000);
		  }
	 }

