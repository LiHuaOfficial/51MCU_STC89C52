#include <REGX52.H>
#include "key.h"
#include "NixieTube.h"
#include "LCD1602.h"

sbit Motor=P1^3;

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	//AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时

  //定时器一定要开中断
  ET0=1;//T0开关
	EA=1;//总开关
	PT0=0;//优先级
}

unsigned char keyNum;
unsigned char nixieNum=0;
unsigned char motorSpeed=0;
unsigned int timerCounter=0;
int main(){

    Timer0Init();
    Motor=0;
    while (1)
    {
        
        keyNum=Key();
        if(keyNum)
        {
            if(keyNum==1) {nixieNum++;nixieNum%=10;motorSpeed=nixieNum*10;}
        }
        NixieCtrl(7,nixieNum);
    }
    
}

//中断初始值太大占用单片机资源，太小让整个周期的时间片太长电机转动可能不连续
void Timer0routine() interrupt 1{
    TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
    timerCounter++;
    timerCounter%=101;
    if(timerCounter<motorSpeed) Motor=1;
    else Motor=0;
}