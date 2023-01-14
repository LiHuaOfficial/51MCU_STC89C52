 #ifndef _LCD1602_
#define _LCD1602_
#include <REGX52.H>

//重定义接口
#define LCD_DB P0
#define LCD_E P2_7
#define LCD_RS P2_6
#define LCD_RW P2_5
/*写入信号
	从P0_0到P0_7
	即LCD_0toLCD_7
*/

#define uint unsigned int
#define uchar unsigned char

//私有接口
void LCD_write_command(uchar command);//写指令函数
void LCD_write_data(uchar dat);//写数据函数
//在某个屏幕位置上显示一个字符,X（0-16),y(1-2) 
void Delayt40us(int t);		//@12.000MHz

//延时函数
//while循环一次2um//声明变量1um
//空函数4um
//_nop_() 1um

//公有接口
void LCD_init(void);//初始化函数
void LCD_disp_char(uchar x,uchar y,uchar dat);
void LCD_disp_string(uchar x,uchar y,uchar * str);
void LCD_clear();
void LCD_disp_number(uchar x,uchar y,int dat,uchar digit);//数字为正
#endif