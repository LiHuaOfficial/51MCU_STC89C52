#ifndef _DS18B20_
#define _DS18B20_
#include <REGX52.H>
#include "OneWire.h"

//发送信号使DS18B20进行温度变换
//精度最高时需要750ms才将温度写入到scratchpad中
void DS18B20_ConvertTemp();

//读出DS18B20中的温度信息
//返回值的低四位分别表示小数1/2 1/4 1/8 1/16
//返回值直接除以16.0即为温度值
int DS18B20_ReadTemp();
#endif