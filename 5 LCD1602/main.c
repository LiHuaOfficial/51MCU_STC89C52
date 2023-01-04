#include "LCD1602.h"

void DelayXms(int x)		//@12.000MHz
{
	while(x--)
	{unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);}
}

int main()
{
	int i=0;
	uchar sayings[5][33]={"GenshinImpact isa GREAT GAME!",
						  "Good morning,SirHave a nice day!",//正好32字符
						  "Hamood?Hamood!  HamoodHabibi!",
						  "IfYou areReadingthis",
						  "You are in      TROUBLE!!!!",
												};
	
	LCD_init();
	
	LCD_disp_number(2,10,-100);
	LCD_disp_number(1,15,-28);
	while(1)
	{
		// LCD_clear();
		// LCD_disp_string(1,0,sayings[i]);
		// DelayXms(1500);
		// i++;
		// if(i>4) i=0;
	}
}