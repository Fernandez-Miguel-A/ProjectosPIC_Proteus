#line 1 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/projectos/LCD2/main.c"
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
#line 5 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/projectos/LCD2/main.c"
uint8_t segment[10]={
63,6,91,79,102,109,125,7,127,103
};



sbit LCD_RS at RD4_bit;
sbit LCD_EN at RD5_bit;
sbit LCD_D4 at RA0_bit;
sbit LCD_D5 at RA1_bit;
sbit LCD_D6 at RA2_bit;
sbit LCD_D7 at RA3_bit;

sbit LCD_RS_Direction at TRISD4_bit;
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISA0_bit;
sbit LCD_D5_Direction at TRISA1_bit;
sbit LCD_D6_Direction at TRISA2_bit;
sbit LCD_D7_Direction at TRISA3_bit;




char txt3[] = "Lcd4bit";
char texto[] = "VIEJO PIC16F877A";


void main()
{
 int i, j;

 TRISB = 0;
 TRISD = 0;
 TRISA = 0;

 ADCON1 |= 0x06;
 PORTD = 0;
 PORTA = 0;

 Lcd_Init();
 Delay_ms(15);

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 Lcd_Out(1,6,txt3);
 Lcd_Out(2,1,"PIC  es la onda!");

 while (1){
 Delay_ms(500);
#line 62 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/projectos/LCD2/main.c"
 i=0;
 for(;i<10; i++){
 PORTB=segment[i];
 Delay_ms(100);
 }


 PORTB=62;

 Lcd_Out(2, 1,(char *) texto);
 Delay_ms(8000);
 }

}
