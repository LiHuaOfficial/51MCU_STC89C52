#ifndef _DS1302_
#define _DS1302_
#include <REGX52.H>

//////////寄存器地址//////////
#define DS1302_SECOND 0x80
#define DS1302_MINUTE 0x82
#define DS1302_HOUR 0x84
#define DS1302_DATE 0x86
#define DS1302_MONTH 0x88
#define DS1302_DAY 0x8a
#define DS1302_YEAR 0x8c
#define DS1302_WP 0x8e
////////////////////////////
extern unsigned char DS1302_TIME[];

unsigned char BtoD(unsigned char);
unsigned char DtoB(unsigned char);
void DS1302_init();
void DS1302_writeByte(unsigned char command,unsigned char _data);
unsigned char DS1302_readByte(unsigned char command);

void DS1302_setTime();
void DS1302_readTime();

#endif