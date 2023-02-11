#include "XPT2046.h"
//#define sbit int

//SPI协议
sbit XPT2046_CS=P3^5;//低电平其他操作才有效
sbit XPT2046_DIN=P3^4;//CLK上升沿输入
sbit XPT2046_DOUT=P3^7;//CLK下降沿输出
sbit XPT2046_DCLK=P3^6;

unsigned int XPT2046_ReadAD(unsigned char command)
{
    unsigned int ADValue=0,i;
    XPT2046_CS=0;
    XPT2046_DCLK=0;
    
    for(i=0;i<8;i++)
    {
        XPT2046_DIN=(command&0x80>>i);
        XPT2046_DCLK=1;
        XPT2046_DCLK=0;
    }

    for(i=0;i<16;i++)
    {   
        XPT2046_DCLK=1;
        XPT2046_DCLK=0;
        if(XPT2046_DOUT){ADValue|=0x8000>>i;}
    }

    XPT2046_CS=1;
    return ADValue>>8;
}
