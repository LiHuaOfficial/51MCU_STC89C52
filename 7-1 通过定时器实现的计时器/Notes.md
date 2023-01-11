## 定时器

+ 标准代码  
初始化
```
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
```
中断函数
```
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
```
+ 注意事项
  + 中断不要忘记打开
  + 时钟只有12T模式，生成初始化函数记得勾
