#ifndef _I2C_
#define _I2C_
#include <REGX52.H>

sbit SCL=P2^1;
sbit SDA=P2^0;

//开始信号
void I2C_Start();

//停止信号
void I2C_Stop();

//发送一个字节
//_data为字节内容
void I2C_SendByte(unsigned char _data);

//接收字节
//返回值为接收的字节
unsigned char I2C_ReceiveByte();

//接收完字节后发出应答，未应答接收设备将做出相应操作
//ackBit为0表示应答，1表示未应答
void I2C_SendAck(unsigned char ackBit);

//发送完字节以后接收设备应答
//返回值同ackBit
unsigned char I2C_ReceiveAck();
#endif