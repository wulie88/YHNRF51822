#ifndef __5110LCD_H
#define __5110LCD_H

#include "nrf_gpio.h"	
///////////////////////////////////////////////////////
//------------------------------------/				 //
#define P_SCE  16 //片选	
#define P_RST  18 //位选
#define P_DC   20 //1写数据，0写指令
#define P_SD   22 // 数据
#define P_SCLK  21 //时钟
#define P_BL  23 //背光
///////////////////////////////////////////////////////

#define sce0   nrf_gpio_pin_clear(P_SCE)  //片选
#define res0   nrf_gpio_pin_clear(P_RST)  //复位,0复位
#define dc0    nrf_gpio_pin_clear(P_DC)   //1写数据，0写指令
#define sdin0  nrf_gpio_pin_clear(P_SD)   //数据
#define sclk0  nrf_gpio_pin_clear(P_SCLK)   //时钟


#define sce1   nrf_gpio_pin_set(P_SCE)  //片选
#define res1   nrf_gpio_pin_set(P_RST)  //复位,0复位
#define dc1    nrf_gpio_pin_set(P_DC)   //1写数据，0写指令
#define sdin1  nrf_gpio_pin_set(P_SD)   //数据
#define sclk1  nrf_gpio_pin_set(P_SCLK)   //时钟
    
void GPIO_Configuration_LCD(void);
void LCD_WriteByte(unsigned char dt, unsigned char command);
void LCD_Init(void);
void LCD_Set_XY(unsigned char X, unsigned char Y);
void LCD_Clear(void);
void LCD_WriteChar(unsigned char X,unsigned char Y,unsigned char c);
void LCD_WriteString_en(unsigned char X,unsigned char Y,unsigned char *s);
void LCD_WriteNumber(unsigned char x,unsigned char y, unsigned long number);
void LCD_write_chinese_string(unsigned char X, unsigned char Y,
                          unsigned char ch_with,unsigned char num,
						  unsigned char line,unsigned char row);
void LCD_Write_cn(unsigned char row, unsigned char page,unsigned char c); //row:列 page:页 dd:字符

void delay_ms(int t);

#endif
