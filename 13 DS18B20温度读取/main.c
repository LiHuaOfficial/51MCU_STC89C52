#include <REGX52.H>
#include "OneWire.h"
#include "LCD1602.h"
#include "DS18B20.h"

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

void LCD_DispTemperature(unsigned char x,unsigned char y,int temp){
    int decimalTemp=0; 
    if(temp<0) {LCD_disp_string(x,y,"-");temp=-temp;}
    else LCD_disp_string(x,y,"+");
    
    //负数应当先取反再计算小数
    decimalTemp+=5000*((temp&(1<<3))>>3);
    decimalTemp+=2500*((temp&(1<<2))>>2);
    decimalTemp+=1250*((temp&(1<<1))>>1);
    decimalTemp+=625*(temp&(1));

    LCD_disp_number(x,y+1,temp>>4,3);
    LCD_disp_string(x,y+4,".");
    LCD_disp_number(x,y+5,decimalTemp,4);
}

int main(){
    int temp;
    LCD_init();
    LCD_disp_string(1,0,"Temperature:");
    while(1)
    {
        Delay1ms();
        DS18B20_ConvertTemp();
        temp=DS18B20_ReadTemp();
        //LCD_disp_number(2,0,temp,5);
        LCD_DispTemperature(2,0,temp);
    }   
}