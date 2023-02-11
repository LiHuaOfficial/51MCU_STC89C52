#include "NixieTube.h"

unsigned char numRef[]={0x3f,0x06,0x5b,0x4f,0x66,
0x6d,0x7d,0x07,0x7f,0x6f};
void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;


	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
void NixieCtrl(unsigned char lightNum,int dsplNum)
{
	//control which one to light
	//P22 P23 P24 control one of eight lights
	P2=(lightNum)<<2;//try not to use P2 again
	
	//control specific number
	P0=numRef[dsplNum];
	
	//in case p2 have changed but p0 still remain
	//there is a period of time during line23&line26
	Delay1ms();
	P0=0;//display nothing
}