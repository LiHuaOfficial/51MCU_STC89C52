#include "74HC595.h"

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

void _595_writeByte(unsigned char byte){
    unsigned char cover=0x80,t=8;

    while(t--){
        SER=byte&cover;//高电平亮
        MCLK=1;MCLK=0;//上升沿读入
        cover=cover>>1;
    }
    
    LCLK=1;LCLK=0;//上升沿输出
}

void matrixLED_writeColumn(unsigned char column,unsigned char _data){
    _595_writeByte(_data);
    //定义最左为第0列
    P0=~(0x80>>column);//低电平亮

    Delay1ms();//亮一会
    //防止writeByte写入的新值直接在原来的位上显示
    P0=~(0x00);//清0 
}

void matrixLED_init(){
    MCLK=0;LCLK=0;
}

