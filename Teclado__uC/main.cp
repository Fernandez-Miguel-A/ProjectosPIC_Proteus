#line 1 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/proyectos/Teclado__uC/main.c"
#line 1 "c:/mikroelektronika/mikroc_pro_for_pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 5 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/proyectos/Teclado__uC/main.c"
uint8_t segment[10]={
63,6,91,79,102,109,125,7,127,103
};



sbit LCD_RS at RC4_bit;
sbit LCD_EN at RC5_bit;
sbit LCD_D4 at RC0_bit;
sbit LCD_D5 at RC1_bit;
sbit LCD_D6 at RC2_bit;
sbit LCD_D7 at RC3_bit;

sbit LCD_RS_Direction at TRISC4_bit;
sbit LCD_EN_Direction at TRISC5_bit;
sbit LCD_D4_Direction at TRISC0_bit;
sbit LCD_D5_Direction at TRISC1_bit;
sbit LCD_D6_Direction at TRISC2_bit;
sbit LCD_D7_Direction at TRISC3_bit;




char txt3[] = "Lcd4bit:";
char texto[] = "VIEJO PIC16F877A";
char Txt[20];

void main()
{
 int i, j;
 char c;

 TRISA = 0xff;

 TRISC = 0;

 ADCON1 |= 0x06;

 PORTC = 0;

 Lcd_Init();
 Delay_ms(15);

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 Lcd_Out(1,1,txt3);
 Lcd_Out(2,1,"PIC  es la onda!");

 while (1){
 c = '1';
 Lcd_Out(1,9,c);
 }

}
