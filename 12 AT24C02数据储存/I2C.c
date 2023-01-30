#include "I2C.h"

void I2C_Start(){
    SCL=1;
    SDA=1;

    SDA=0;//核心操作，在SCL=1时SDA下拉

    SCL=0;
}

void I2C_Stop(){
    SDA=0;
    SCL=1;

    SDA=1;//核心操作，在SCL=1时SDA上拉
}

void I2C_SendByte(unsigned char _data){
    unsigned char i;
    for(i=0;i<8;i++){
        SDA=_data&(0x80>>i);
        SCL=1;
        SCL=0;
    }
}

unsigned char I2C_ReceiveByte(){
   unsigned char _data=0x00,i;

   SDA=1;
   for(i=0;i<8;i++){
        SCL=1;
        if(SDA) _data|=(0x80>>i);
        SCL=0;
   }

   return _data;   
}

//0表示应答
void I2C_SendAck(unsigned char ackBit){
    SDA=ackBit;
    SCL=1;SCL=0;
}

unsigned char I2C_ReceiveAck(){
    unsigned char ackBit=0;
    SDA=1;
    SCL=1;
    ackBit=SDA;
    SCL=0;
    return ackBit;
}


