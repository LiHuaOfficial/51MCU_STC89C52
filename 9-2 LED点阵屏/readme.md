## 点阵屏和74HC595
通过扫描列显示完整图像
```
//向595写入数据，操控点阵屏行（1点亮），高位在上
//byte为要写入的8位二进制数
void _595_writeByte(unsigned char byte);

//指定列并写入数据从而操控点阵屏
//column为列号从左到右分别为0~7
//_data为要写入的8位二进制数
void matrixLED_writeColumn(unsigned char column,unsigned char _data);

//其实是初始化74HC595的两个时钟
void matrixLED_init();
```
> 74HC595是一个8位串行输入、并行输出的位移缓存器
+ 关于74HC595 

  + 每次SRCLK上升沿读入SER的数据
  + RCLK上升沿输出读入的数据
  + 额外接电源，驱动能力更强
