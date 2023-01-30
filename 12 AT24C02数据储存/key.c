#include "key.h"

void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}

unsigned char Key(){
    if(P3_1==0){Delay10ms();while(P3_1==0){};return 1;}
    if(P3_0==0){Delay10ms();while(P3_0==0){};return 2;}
    if(P3_2==0){Delay10ms();while(P3_2==0){};return 3;}
    if(P3_3==0){Delay10ms();while(P3_3==0){};return 4;}
    return 0;
}