#ifndef NIXIE_TUBE
#define NIXIE_TUBE
#include <REGX52.H>

//控制数码管
//lightNum表示控制第几个灯亮起 0~7
//dsplNum表哪个数字亮起
void NixieCtrl(unsigned char lightNum,int dsplNum);



#endif