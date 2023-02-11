#include <REGX52.H>
#include "LCD1602.h"
#include "XPT2046.h"

unsigned int ADValue;
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
int main()
{
    LCD_init();
    while (1)
    {
        ADValue=XPT2046_ReadAD(XPT2046_AIN0);
        LCD_disp_number(2,1,ADValue,3);
        Delay10ms();
    }  
}