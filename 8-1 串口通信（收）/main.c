#include <REGX52.H>

// void UART_init(){
//     SCON=0x50;//SM0=0 SM1=1
//     PCON |= 0x80;//

//     //定时器1
// 	TMOD &= 0x0F;		//设置定时器模式
//     TMOD |= 0x20;
// 	TL1 = 0xF3;		//设置定时初始值
// 	TH1 = 0xF3;		//设置定时重载值

// 	ET1=0;          //禁止定时器1中断
// 	TR1 = 1;		//定时器1开始计时

//     //让接收引发中断
//     EA=1;
//     ES=1;
// }

void UartInit(void)		//4800bps@11.0592MHz//注意本机频率！
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	// AUXR &= 0xBF;		//定时器时钟12T模式
	// AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;		//设置定时初始值
	TH1 = 0xF4;		//设置定时重载值
	ET1 = 0;		//禁止定时器%d中断
	TR1 = 1;		//定时器1开始计时

    EA=1;
    ES=1;
}

void UART_sendByte(unsigned char byte){
    SBUF=byte;      //写入即发送
    while(TI==0);   //发送结束以后自动置1
    TI=0;           //手动复位
}

void Delay500ms()		//@12.000MHz
        {
            unsigned char i, j, k;

            
            i = 4;
            j = 205;
            k = 187;
            do
            {
                do
                {
                    while (--k);
                } while (--j);
            } while (--i);
        }
//unsigned char cnt=0;
int main(){
    //UART_init();
    UartInit();
    while (1)
    {
        // UART_sendByte(cnt);
        // cnt++;
        // Delay500ms();		//@12.000MHz
       
    }
    
}

void UART_routine(void) interrupt 4
{
    if(RI==1) //成功接收
    {
        P2=SBUF;
        UART_sendByte(SBUF);
        RI=0;
    }
}