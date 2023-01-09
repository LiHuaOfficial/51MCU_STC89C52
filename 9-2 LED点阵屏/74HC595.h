#ifndef _74HC595_
#define _74HC595_
#include <REGX52.H>


sbit LCLK=P3^5;//锁存上升沿
sbit MCLK=P3^6;//移位上升沿
sbit SER=P3^4;//数据输入

void _595_writeByte(unsigned char byte);
void matrixLED_writeColumn(unsigned char column,unsigned char _data);
void matrixLED_init();








#endif