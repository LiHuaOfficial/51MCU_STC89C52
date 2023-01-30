#include <REGX52.H>
#include "AT24C02.h"
#include "LCD1602.h"

unsigned char test;

void Delay5ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 9;
	j = 244;
	do
	{
		while (--j);
	} while (--i);
}

int main(){
     LCD_init();
     LCD_disp_string(1,0,"hamood");
     AT24C02_WriteByte(1,66);
     Delay5ms();
     test=AT24C02_ReadByte(1);
     LCD_disp_number(2,0,test,2);
     while(1){

     }
}