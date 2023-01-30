#ifndef _AT24C02_
#define _AT24C02_
#include <REGX52.H>
#include "I2C.h"

#define AT24C02_ADDRESS 0xa0
#define W 0
#define R 1

//AT24C02储存空间为256K
//故地址范围为0~255

//向AT24C02芯片写入数据
//wordAdress范围如上，_data为一个字节大小
//写完以后必须延时，5ms为写周期最大值
void AT24C02_WriteByte(unsigned char wordAdress,unsigned char _data);

//从AT24C02芯片读数据
//wordAdress范围如上
unsigned char AT24C02_ReadByte(unsigned char wordAdress);

#endif