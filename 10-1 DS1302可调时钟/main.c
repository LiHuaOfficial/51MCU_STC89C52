#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "key.h"

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	//AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时

    //定时器一定要开中断
    ET0=1;//T0开关
	EA=1;//总开关
	PT0=0;//优先级
}

unsigned char keyNum;
unsigned char MODE=0,timeSelect,timeSelectFlag=1;
unsigned int timer0Count=0;

void ShowTime(){
    DS1302_readTime();
    LCD_disp_number(2,6,DS1302_TIME[0],2);
    LCD_disp_number(2,3,DS1302_TIME[1],2);
    LCD_disp_number(2,0,DS1302_TIME[2],2);
    LCD_disp_number(1,6,DS1302_TIME[3],2);
    LCD_disp_number(1,3,DS1302_TIME[4],2);
    LCD_disp_number(1,0,DS1302_TIME[5],2);
}

void SetTime(){
    if(keyNum==2){
        timeSelect++;
        timeSelect%=6;
    }
    if(keyNum==3){
        DS1302_TIME[timeSelect]++;
        if(DS1302_TIME[0]>59) DS1302_TIME[0]=0;
        if(DS1302_TIME[1]>59) DS1302_TIME[1]=0;
        if(DS1302_TIME[2]>23) DS1302_TIME[2]=0;
        if(DS1302_TIME[3]>31) DS1302_TIME[3]=0;//姑且忽略大小月
        if(DS1302_TIME[4]>12) DS1302_TIME[4]=0;
        if(DS1302_TIME[5]>99) DS1302_TIME[5]=0;
    }
    if(keyNum==4){
        DS1302_TIME[timeSelect]--;
        if(DS1302_TIME[0]==255) DS1302_TIME[0]=59;
        if(DS1302_TIME[1]==255) DS1302_TIME[1]=59;
        if(DS1302_TIME[2]==255) DS1302_TIME[2]=23;
        if(DS1302_TIME[3]==255) DS1302_TIME[3]=31;
        if(DS1302_TIME[4]==255) DS1302_TIME[4]=12;
        if(DS1302_TIME[5]==255) DS1302_TIME[5]=99;
    }

    //处于修改模式的显示&闪烁
    if(timeSelect==0&&timeSelectFlag==0) LCD_disp_string(2,6,"  ");
    else LCD_disp_number(2,6,DS1302_TIME[0],2);
    if(timeSelect==1&&timeSelectFlag==0) LCD_disp_string(2,3,"  ");
    else LCD_disp_number(2,3,DS1302_TIME[1],2);
    if(timeSelect==2&&timeSelectFlag==0) LCD_disp_string(2,0,"  ");
    else LCD_disp_number(2,0,DS1302_TIME[2],2);
    if(timeSelect==3&&timeSelectFlag==0) LCD_disp_string(1,6,"  ");
    else LCD_disp_number(1,6,DS1302_TIME[3],2);
    if(timeSelect==4&&timeSelectFlag==0) LCD_disp_string(1,3,"  ");
    else LCD_disp_number(1,3,DS1302_TIME[4],2);
    if(timeSelect==5&&timeSelectFlag==0) LCD_disp_string(1,0,"  ");
    else LCD_disp_number(1,0,DS1302_TIME[5],2);
}

int main(){
    
    DS1302_init();
    LCD_init();
    Timer0Init();

    DS1302_setTime();

    LCD_disp_string(1,0,"  -  -  ");
    LCD_disp_string(2,0,"  :  :  ");

    while (1){
        //ShowTime();
        // if(timeSelectFlag) LCD_disp_number(1,9,1,1);
        // else LCD_disp_number(1,9,0,1);

        keyNum=Key();
        if(keyNum==1){
            if(MODE==0){MODE=1;}
            else if(MODE==1) {MODE=0;DS1302_setTime();}//改完最后set
        }
        switch (MODE)
        {
        case 0:ShowTime();break;
        case 1:SetTime();break;
        }
        
    }
}

void Timer0routine() interrupt 1{
    TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
    timer0Count++;
    if(timer0Count>4000)
    {
        timer0Count=0;
        timeSelectFlag=!timeSelectFlag;
        
    }
}