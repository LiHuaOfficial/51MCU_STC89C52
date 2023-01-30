#include "OneWire.h"

unsigned char OneWire_Init(){
    unsigned char i;
    unsigned char ackBit;
    //发出信号
    OneWire_ctrl=1;
    OneWire_ctrl=0;
	i = 227;
	while (--i);//延时500us
    OneWire_ctrl=1; 
    //接收从机信号
    i = 29;
	while (--i);//延时70us
    ackBit=OneWire_ctrl;
    i = 227;
	while (--i);//延时500us
    return ackBit;
}

void OneWire_SendBit(unsigned char _bit){
    unsigned char i;
    OneWire_ctrl=0;
    i = 3;while (--i);//10us左右
    OneWire_ctrl=_bit;

    i = 21;while (--i);//50us左右
    OneWire_ctrl=1;
}

unsigned char OneWire_ReceiveBit(){
    unsigned char i;
    unsigned char reciBit;
    OneWire_ctrl=0;
    i = 2;while (--i);//5us
    OneWire_ctrl=1;
    i = 2;while (--i);
    reciBit=OneWire_ctrl;
    i = 21;while (--i);//50us左右
    return reciBit;
}

void OneWire_SendByte(unsigned char _data){
    unsigned char i;
    for(i=0;i<8;i++)
    {
        OneWire_SendBit(_data&(0x01<<i));
    }
}

unsigned char OneWire_ReceiveByte(){
    unsigned char _data=0,i;
    unsigned char reciBit;
    for(i=0;i<8;i++){
        reciBit=OneWire_ReceiveBit();
        _data|=(reciBit<<i);
    }
    return _data;
}