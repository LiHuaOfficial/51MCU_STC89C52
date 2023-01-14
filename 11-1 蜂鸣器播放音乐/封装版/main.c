#include <REGX52.H>
#include "music.h"
#include "matrixKey.h"
#include "LCD1602.h"

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

unsigned char FreqFlag=0,keyNum;

int main()
{
	//unsigned char musicFlag;
	Timer0Init();
	LCD_init();
	LCD_disp_string(2,0,"SPEED:");
	LCD_disp_string(1,0,"PLAYING:None");
	SPEED=90;
	LCD_disp_number(2,6,SPEED,3);

    while(1)
    {
		keyNum=MatrixKey();
		if(keyNum){
			if(keyNum>=1&&keyNum<=4) {
				LCD_disp_number(1,8,keyNum,4);
				PlayMusic(keyNum-1);//播放对应音乐
				LCD_disp_string(1,8,"None");
			}
			//节拍速度改变
			if(keyNum==5) {
				SPEED=SPEED+5;
				LCD_disp_number(2,6,SPEED,3);
			}			 
			if(keyNum==9) {
				SPEED=SPEED-5;
				LCD_disp_number(2,6,SPEED,3);
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