#include "DS1302.h"

unsigned char DS1302_TIME[]={
    50,59,23,11,1,23,2
};

sbit SCLK=P3^6;     //输入（上升沿）输出（下降沿）使能
sbit IO=P3^4;       //
sbit CE=P3^5;       //高电平可正常读写

unsigned char BtoD(unsigned char _data){
    return _data/16*10+_data%16;//高4位表示10位数，低4位表示个位数
}
unsigned char DtoB(unsigned char _data){
    return _data/10*16+_data%10;
}
void DS1302_init(){
    CE=0;
    SCLK=0;
}

void DS1302_writeByte(unsigned char command,unsigned char _data){
    unsigned char i;
    CE=1;
    for(i=0;i<8;i++){
        IO=command&(0x01<<i);
        SCLK=1;
        SCLK=0;
    }
    for(i=0;i<8;i++){
        IO=_data&(0x01<<i);
        SCLK=1;
        SCLK=0;
    }
    CE=0;
}

unsigned char DS1302_readByte(unsigned char command){
    unsigned char i,_data=0x00;
    command|=0x01;//传入预定义的写地址，或1变读
    CE=1;
    for(i=0;i<8;i++){
        IO=command&(0x01<<i);
        SCLK=0;//先给0保证写入完成时CLK为1
        SCLK=1;//于是就可以直接给下降沿以读取
    }
    for(i=0;i<8;i++){
        SCLK=1;
        SCLK=0;
        if(IO) _data|=(0x01<<i);
    }
    CE=0;
    IO=0;
    return _data;//读出的是4位BCD码
}

void DS1302_setTime(){
    DS1302_writeByte(DS1302_WP,0x00);

    DS1302_writeByte(DS1302_SECOND,DtoB(DS1302_TIME[0]));
    DS1302_writeByte(DS1302_MINUTE,DtoB(DS1302_TIME[1]));
    DS1302_writeByte(DS1302_HOUR,DtoB(DS1302_TIME[2]));
    DS1302_writeByte(DS1302_DATE,DtoB(DS1302_TIME[3]));
    DS1302_writeByte(DS1302_MONTH,DtoB(DS1302_TIME[4]));
    DS1302_writeByte(DS1302_YEAR,DtoB(DS1302_TIME[5]));
    DS1302_writeByte(DS1302_DAY,DtoB(DS1302_TIME[6]));
        
    DS1302_writeByte(DS1302_WP,0x80);
}
void DS1302_readTime(){
    DS1302_TIME[0]=BtoD(DS1302_readByte(DS1302_SECOND));
    DS1302_TIME[1]=BtoD(DS1302_readByte(DS1302_MINUTE));
    DS1302_TIME[2]=BtoD(DS1302_readByte(DS1302_HOUR));
    DS1302_TIME[3]=BtoD(DS1302_readByte(DS1302_DATE));
    DS1302_TIME[4]=BtoD(DS1302_readByte(DS1302_MONTH));
    DS1302_TIME[5]=BtoD(DS1302_readByte(DS1302_YEAR));
    DS1302_TIME[6]=BtoD(DS1302_readByte(DS1302_DAY));
}