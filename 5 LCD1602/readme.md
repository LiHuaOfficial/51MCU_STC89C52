# LCD1602
  
包含以下操作：  
```
/*x 1~2 y 0~16*/

LCD_init(void);//初始化函数  
LCD_disp_char(uchar x,uchar y,uchar dat);  
LCD_disp_string(uchar x,uchar y,uchar * str);  
LCD_clear(void);  
LCD_disp_number(uchar x,uchar y,uint dat,uchar digit);//数字为int16范围，当数字位数小于digit时自动补0  

```
