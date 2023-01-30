#include "AT24C02.h"

void AT24C02_WriteByte(unsigned char wordAddress,unsigned char _data){
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS+W);//指定设备与读写
    if(I2C_ReceiveAck());//错误处理
    I2C_SendByte(wordAddress);
    if(I2C_ReceiveAck());
    I2C_SendByte(_data); 
    if(I2C_ReceiveAck());
    I2C_Stop();
}

unsigned char AT24C02_ReadByte(unsigned char wordAdress){
    unsigned char _data;
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS+W);
    if(I2C_ReceiveAck());
    I2C_SendByte(wordAdress);
    if(I2C_ReceiveAck());

    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS+R);
    if(I2C_ReceiveAck());

    _data=I2C_ReceiveByte();
    I2C_SendAck(1);//结束发送
    I2C_Stop();

    return _data;
}