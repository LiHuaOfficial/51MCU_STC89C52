#include "music.h"

unsigned char SPEED=90;

unsigned int code FreqTable[]=
{
0,
63777,63872,63969,64054,64140,64216,64291,64360,64426,64489,64547,64603,
64655,64704,64751,64795,64837,64876,64913,64948,64981,65012,65042,65070,
65095,65495,65144,65166,65186,65206,65225,65242,65259,65274,65289,65303,
};
//code关键字表示储存在ROM当中
//变成只读
unsigned char code Music[NUM_OF_MUSIC][SIZE_OF_MUSIC]={
{
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
},
{
M2,4,M2,4,M2,4,M4,4,
M2,4,M2,4,M4,4,M5,4,
M6,3,M5,3,M4,3,M5,8,

M2,4,M2,4,M2,4,M4,4,
M5,4,M2,4,M4,4,M5,4,
M6,3,M5,3,M4,3,M5,8,

M4,4,M6,4,M5,4,M6,4,
M4,4,M5,4,M6,4,M5,4,
M5,4,M4,2,M2,2,

M2,4,M4,4,M5,4,M6,4,
H1,4,M4,4,M4,4,M5,4,
M5,4,M4,2,M2,2,

M2,4,M2,4,M2,4,M4,4,
M2,4,M4,4,M6,4,M5,8,

M2,4,M2,4,M2,4,M4,4,
M2,4,M4,4,M6,4,M5,8,

M5,4,M5,4,M4,4,M6,4,
M5,4,M6,4,M4,4,M5,4,
M6,4,M5,4,M5,4,M4,2,M2,6,

M2,4,M4,4,M5,4,M6,4,
H1,4,M4,4,M4,4,M5,4,
M5,4,M4,2,M2,6
},
{
M3,4,M6,4
},
{
M3,4,M6,4
}
};//音调&节拍

extern unsigned char FreqFlag;
extern unsigned char SPEED;

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

void PlayMusic(unsigned char musicTag){
    unsigned char musicPlayingFlag=0;
    //开始播音乐
    TR0=1;
    while(1){
        FreqFlag=Music[musicTag][musicPlayingFlag];
        musicPlayingFlag++;
        Delay(SPEED*Music[musicTag][musicPlayingFlag]);
        musicPlayingFlag++;
        //每个音之间的停顿
        TR0=0;
        Delay(5);
        TR0=1;
        //结束
        if(musicPlayingFlag>SIZE_OF_MUSIC-1){
            TR0=0;
            break;
        }
    }
}