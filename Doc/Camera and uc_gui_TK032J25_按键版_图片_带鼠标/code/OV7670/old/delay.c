
#include "delay.h"

void OV7670_delay_us(unsigned int i)
 {  
    //i=i*72;   
    while( i--)
       {	
        
        }
 }		  

//    ∫¡√Îº∂—” ±∫Ø ˝	 
void OV7670_delay_ms(unsigned int time)
	 {
	  while(time--)
	  	  {	
		   OV7670_delay_us(1000);
		   ;
		  }
	 }

