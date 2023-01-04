#include <REGX52.H>
#include "LCD1602.h"
#include "matrixKey.h"

void Timer0Init(void)		//1微秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x20;		//设置定时初始值
	TH0 = 0xD1;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时

    //中断系统的配置
	ET0=1;//T0开关
	EA=1;//总开关
	PT0=0;//优先级
}

unsigned char sec=0,min=0,hour=0;
char currentPage=0;

unsigned char pages[5][17]={{"< CLOCK:       >"},
                            {"< Reset?   Y/N >"},
                            {"< AddHour? Y/N >"},
                            {"< AddMin?  Y/N >"},
                            {"< AddSec?  Y/N >"}};

int main(){
    unsigned char keyNum=0;
    LCD_init();
    LCD_disp_string(1,0,pages[currentPage]);
    LCD_disp_string(2,0,"  :  :");
    Timer0Init();
    while(1)
    {
        LCD_disp_number(2,0,hour,2);
        LCD_disp_number(2,3,min,2);
        LCD_disp_number(2,6,sec,2);
        keyNum=MatrixKey();
        if(keyNum==1){
            currentPage--;
            if(currentPage<0) currentPage=4;
            LCD_disp_string(1,0,pages[currentPage]);
            }
        if(keyNum==2){
            currentPage++;
            if(currentPage>4) currentPage=0;
            LCD_disp_string(1,0,pages[currentPage]);
            }
        if(keyNum==4)
        {
            if(currentPage==1){hour=0,min=0,sec=0;}
            if(currentPage==2){hour++;}
            if(currentPage==3){min++;}
            if(currentPage==4){sec++;}
        }
        
    }
}

void Timer0Routine(void) interrupt 1
{
    static int timer0Count=0;
    TL0 = 0x20;		//设置定时初始值
	TH0 = 0xD1;		//设置定时初始值
    timer0Count++;
    if(timer0Count>=1000)
    {
        timer0Count=0;
        sec++;
        if(sec>=60) {min++;sec=0;}
        if(min>=60) {hour++;min=0;}
        if(hour>=24) hour=0;
    }    
}