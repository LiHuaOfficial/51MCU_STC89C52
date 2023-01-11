## DS1302
> 具有涓细电流充电能力的低功耗实时时钟芯片
会自动走时，判断大小月，平闰年
```
//////////寄存器地址//////////
#define DS1302_SECOND 0x80
#define DS1302_MINUTE 0x82
#define DS1302_HOUR 0x84
#define DS1302_DATE 0x86
#define DS1302_MONTH 0x88
#define DS1302_DAY 0x8a
#define DS1302_YEAR 0x8c
#define DS1302_WP 0x8e//写保护开关
////////////////////////////

//储存时间的数组
extern unsigned char DS1302_TIME[];

//十进制与BCD码的转换
unsigned char BtoD(unsigned char);
unsigned char DtoB(unsigned char);

//初始化CE（高电平工作）和SCLK（输入输出的时钟信号）
void DS1302_init();

//向DS1302写入数据
//command为预先给出的寄存器地址
//_data为BCD码形式的数据
void DS1302_writeByte(unsigned char command,unsigned char _data);

//从DS1302读出数据
//command为预先给出的寄存器地址
//返回值为BCD码形式的数据
unsigned char DS1302_readByte(unsigned char command);

//将DS1302_TIME[]数组的内容写入到DS1302中
//顺序为：秒、分、时、日、月、年、星期
void DS1302_setTime();

//将DS1302中的数据读出到数组中
//同上
void DS1302_readTime();
```
