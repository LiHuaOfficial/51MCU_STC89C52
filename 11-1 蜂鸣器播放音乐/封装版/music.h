#ifndef _MUSIC_
#define _MUSIC_
#include<REGX52.H>

sbit buzzer=P2^5;

/////////////////////////////////
/*速度和音调*/
//SPEED现在是变量
//#define SPEED 100//表示1/4拍

#define PAUSE 0
/*
1 1# 2 2# 3 4 4# 5 5# 6 6# 7
*/
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

#define NUM_OF_MUSIC 4
#define SIZE_OF_MUSIC 200


extern unsigned char code Music[NUM_OF_MUSIC][SIZE_OF_MUSIC];
extern unsigned int code FreqTable[];
extern unsigned char SPEED;

void PlayMusic(unsigned char musicTag);
void Delay(unsigned int t);

#endif