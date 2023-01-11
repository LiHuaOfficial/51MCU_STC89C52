#include <REGX52.H>

/////////////////////////////////
/*速度和音调*/
#define SPEED 125//表示1/4拍

#define PAUSE 0
//低音
#define L1 1
#define L1U 2
#define L2 3
#define L2U 4
#define L3 5
#define L4 6
#define L4U 7
#define L5 8
#define L5U 9
#define L6 10
#define L6U 11
#define L7 12
//中音
#define M1 13
#define M1U 14
#define M2 15
#define M2U 16
#define M3 17
#define M4 18
#define M4U 19
#define M5 20
#define M5U 21
#define M6 22
#define M6U 23
#define M7 24
//高音
#define H1 25
#define H1U 26
#define H2 27
#define H2U 28
#define H3 29
#define H4 30
#define H4U 31
#define H5 32
#define H5U 33
#define H6 34
#define H6U 35
#define H7 36
////////////////////////////////

sbit buzzer=P2^5;

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	//AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD=TMOD|0x01;		//16位模式
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时

    ET0=1;//T0开关
	EA=1;//总开关
	PT0=0;//优先级
}
void Delay(unsigned int t)		//@11.0592MHz
{
	while (t--)
	{
		unsigned char i, j;
		//_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}	
}
/*
1 1# 2 2# 3 4 4# 5 5# 6 6# 7
*/
unsigned int code FreqTable[]=
{
0,
63777,63872,63969,64054,64140,64216,64291,64360,64426,64489,64547,64603,
64655,64704,64751,64795,64837,64876,64913,64948,64981,65012,65042,65070,
65095,65495,65144,65166,65186,65206,65225,65242,65259,65274,65289,65303,
};
//code关键字表示储存在ROM当中
//变成只读
unsigned char code Music[]={
L6,6,L7,2,
M1,6,L6,2,
M1,4,L7,2,L6,2,
L7,4,L3,2,PAUSE,2,
L7,6,M1,2,
M2,6,L7,2,
M2,2,M2,2,M1,2,L7,2,
L6,8,
M3,4,M6,4,
M5,4,M6,2,M5,2,
M4,4,M3,2,M2,2,
M3,4,L6,4,
PAUSE,2,M4,4,M2,2,
M3,6,M1,2,
L7,2,L3,2,M1,2,L7,2,
L6,8,
//重复
M3,4,M6,4,
M5,4,M6,2,M5,2,
M4,4,M3,2,M2,2,
M3,4,L6,4,
PAUSE,2,M4,4,M2,2,
M3,6,M1,2,
L7,2,L3,2,M1,2,L7,2,
L6,8
};//音调&节拍
unsigned char FreqFlag=0;
int main()
{
	unsigned char musicFlag;
	Timer0Init();
    while(1)
    {
		if(P3_1==0){
			Delay(10);
			while(P3_1==0){};
			//开始播音乐
			musicFlag=0;TR0=1;

			while(1){
			FreqFlag=Music[musicFlag];
			musicFlag++;
			Delay(SPEED*Music[musicFlag]);
			musicFlag++;
			//每个音之间的停顿
			TR0=0;
			Delay(5);
			TR0=1;
			//结束
			if(musicFlag>sizeof(Music)-1){
				TR0=0;
				break;
			}
			}
		}
        
    }
}

void Timer0_Rountine(void) interrupt 1{
	if(FreqTable[FreqFlag]){
		TH0=FreqTable[FreqFlag]/256;
		TL0=FreqTable[FreqFlag]%256;
    	buzzer=!buzzer;
	}
}