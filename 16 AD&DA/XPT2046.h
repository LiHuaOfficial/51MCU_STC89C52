  #ifndef XPT2046
#define XPT2046

#include <REGX52.H>

#define XPT2046_AIN0 0x9c
#define XPT2046_AIN1 0xdc
#define XPT2046_AIN2 0xac 
#define XPT2046_AIN3 0xec

unsigned int XPT2046_ReadAD(unsigned char command);
#endif