#include "stm32f10x.h"
#include "serialnum.h"

void checkSerialNUM(void)
{
	u32 Dev_Serial0, Dev_Serial1, Dev_Serial2;

	Dev_Serial0 = *(vu32*)(0x1FFFF7E8);
    Dev_Serial1 = *(vu32*)(0x1FFFF7EC);
    Dev_Serial2 = *(vu32*)(0x1FFFF7F0);

    if(Dev_Serial0!=Serial0_NUM||Dev_Serial1!=Serial1_NUM||Dev_Serial2!=Serial2_NUM)
   {
	    //printf("\r\n’‚ «µ¡∞Êµƒ!");
        //while(1);
    }
}



