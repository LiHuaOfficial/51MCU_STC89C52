## AT24C02使用

```
//AT24C02储存空间为256K 
//故地址范围为0~255

//向AT24C02芯片写入数据 
//wordAdress范围如上，_data为一个字节大小 
//写完以后必须延时，5ms为写周期最大值 
void AT24C02_WriteByte(unsigned char wordAdress,unsigned char _data); 

//从AT24C02芯片读数据 
//wordAdress范围如上 
unsigned char AT24C02_ReadByte(unsigned char wordAdress);
```
