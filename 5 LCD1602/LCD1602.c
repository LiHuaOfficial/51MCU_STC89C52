#include "LCD1602.h"

void Delayt40us(int t)		//@12.000MHz
{
	int n=20*t;
	while(n--);
}

void LCD_write_command(uchar command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DB=command;
	
	LCD_E=1;LCD_E=0;//给一个下降沿
	
	Delayt40us(1);
}

void LCD_init()
{
	//不知道是什么玄学问题
	//重复四次就完事了
	LCD_write_command(0x38);//设置 8 位格式，2 行，5x7
	Delayt40us(1);
	LCD_write_command(0x38);
	Delayt40us(1);
	LCD_write_command(0x38);
	Delayt40us(1);
	LCD_write_command(0x38);
	Delayt40us(1);
	
	LCD_write_command(0x0c);//整体显示，关光标，不闪烁
	LCD_write_command(0x06);//设定输入方式，增量不移位
	LCD_write_command(0x01);//清除屏幕显示
	Delayt40us(10);
}

void LCD_write_data(uchar dat)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DB=dat;	
	LCD_E=1;LCD_E=0;//给一个下降沿	
	Delayt40us(1);
}

//公有接口
void LCD_clear()
{
	LCD_write_command(0x01);
	Delayt40us(5);//不延时可能会导致写入的字符被擦
}

void LCD_disp_char(uchar y,uchar x,uchar dat)//x 0~16 y 1~2
{
	uchar address;
	
	//第一位固定为1，后三位决定行，再后四位决定列
	if(y==1) address=0x80+x;//1000_0000+x
	else address=0xc0+x;//1100_0000+1
	
	LCD_write_command(address);
	LCD_write_data(dat);
}

void LCD_disp_string(uchar y,uchar x,uchar * str)
{
	uchar address;int i=0;uchar j=15-x;
	uchar flag=1;
	
	if(y==1) address=0x80+x;//1000_0000+x
	else address=0x80+0x40+x;//1100_0000+x
	
	LCD_write_command(address);
	while(str[i]!='\0')
	{	
		LCD_write_data(str[i]);
		i++;
		if(y==1&&i>j&&flag) {LCD_write_command(0x80+0x40);flag=0;}
	}
}
void LCD_disp_number(uchar x,uchar y,int dat,uchar digit)
{
	uchar datSize=0,tmp[6],res[6],i,tdatSize;
	if(dat<0){
		dat=-dat;
		LCD_disp_string(x,y,"-");	
		y++;
		if(y>15){x++,y=0;}
	}
	
	while(dat){
		tmp[datSize]=dat%10;
		dat/=10;
		datSize++;
	}
	//tmp[datSize]='\0';
	res[digit]='\0';
	tdatSize=datSize;
	dat=digit-datSize;//计算0占位	
	for(i=0;i<digit||i<tdatSize;i++)
	{
		if(dat>0){
			dat--;
			res[i]='0';
		}
		else{
			res[i]=tmp[--datSize];
			res[i]=res[i]+'0';
		}
		
	}
	LCD_disp_string(x,y,res);
}
	