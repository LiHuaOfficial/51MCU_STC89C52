#include "matrixKey.h"

void Delay10ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 20;
	j = 113;
	do
	{
		while (--j);
	} while (--i);
}

unsigned char MatrixKey()
{
    unsigned char keyNum=0;

	//每次给一个0~3内一个0
	//然后检测这一列另一段是不是也是0
	//都为0则表示按下
	P1=0xff;P1_3=0;
	if(P1_7==0){Delay10ms();while (P1_7==0){};keyNum=1;}
	if(P1_6==0){Delay10ms();while (P1_6==0){};keyNum=5;}
	if(P1_5==0){Delay10ms();while (P1_5==0){};keyNum=9;}
	if(P1_4==0){Delay10ms();while (P1_4==0){};keyNum=13;}

	P1=0xff;P1_2=0;
	if(P1_7==0){Delay10ms();while (P1_7==0){};keyNum=2;}
	if(P1_6==0){Delay10ms();while (P1_6==0){};keyNum=6;}
	if(P1_5==0){Delay10ms();while (P1_5==0){};keyNum=10;}
	if(P1_4==0){Delay10ms();while (P1_4==0){};keyNum=14;}

	P1=0xff;P1_1=0;
	if(P1_7==0){Delay10ms();while (P1_7==0){};keyNum=3;}
	if(P1_6==0){Delay10ms();while (P1_6==0){};keyNum=7;}
	if(P1_5==0){Delay10ms();while (P1_5==0){};keyNum=11;}
	if(P1_4==0){Delay10ms();while (P1_4==0){};keyNum=15;}

	P1=0xff;P1_0=0;
	if(P1_7==0){Delay10ms();while (P1_7==0){};keyNum=4;}
	if(P1_6==0){Delay10ms();while (P1_6==0){};keyNum=8;}
	if(P1_5==0){Delay10ms();while (P1_5==0){};keyNum=12;}
	if(P1_4==0){Delay10ms();while (P1_4==0){};keyNum=16;}
	
    return keyNum;
}