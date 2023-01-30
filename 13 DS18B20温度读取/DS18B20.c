#include "DS18B20.h"

void DS18B20_ConvertTemp(){
    OneWire_Init();
    OneWire_SendByte(0xcc);//skip rom(DS18B20的rom指令之一)
    OneWire_SendByte(0x44);//功能指令 更新温度
}

int DS18B20_ReadTemp(){
    unsigned char tempLSB,tempMSB;
    
    int temp;
    OneWire_Init();
    OneWire_SendByte(0xcc);
    OneWire_SendByte(0xbe);//功能指令 读scratchpad中的数据
    tempLSB=OneWire_ReceiveByte();
    tempMSB=OneWire_ReceiveByte();
    temp=(tempMSB<<8)|tempLSB;//计算完成时才根据类型进行截断
    
    return temp;
    //低四位表示小数1/2 1/4 1/8 1/16
    //可以直接将temp除以16.0得到精确的浮点数
    
}