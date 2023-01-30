#ifndef _ONEWIRE_
#define _ONEWIRE_
#include <REGX52.H>
/*
 DS18B20采用的单总线协议的各种操作
*/
sbit OneWire_ctrl=P3^7;

//1wire总线初始化
//返回1时则从机有回应，0反之
unsigned char OneWire_Init();

/*初始化以后可进行以下操作*/

//主机通过1wire总线发出1位信息
//_bit为0或1
void OneWire_SendBit(unsigned char _bit)

//主机通过1wire总线发出8位信息
void OneWire_SendByte(unsigned char _data);

//主机通过1wire总线接收1位信息
//返回值为0或1
unsigned char OneWire_ReceiveBit();

//主机通过1wire总线接收8位信息
unsigned char OneWire_ReceiveByte();
#endif