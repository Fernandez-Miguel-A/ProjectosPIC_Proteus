#line 1 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/PWM/main.c"
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
#line 5 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/PWM/main.c"
uint8_t segment[10]={
63,6,91,79,102,109,125,7,127,103
};



sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;


sbit SUBE at RB6_bit;
sbit BAJA at RB7_bit;

int Velo1 = 50;


char txt3[] = "Lcd4bit";
char texto[] = "NUEVO PIC18F2550";


void main()
{
 int i, j;

 ADCON1 |= 0x0F;
#line 44 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/PWM/main.c"
 CMCON |= 0x07;

 TRISB = 0;
 TRISB6_bit = 1;
 TRISB7_bit = 1;

 TRISC2_bit = 0;


 PWM1_Init(5000);

 PWM1_Set_Duty(Velo1);


 PWM1_Start();


 Lcd_Init();
 Delay_ms(15);

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);


 Lcd_Out(1,6,txt3);
 Lcd_Out(2,1,"PIC  es la onda!");
 Delay_ms(500);
 while (1){

 Lcd_Out(2, 1, texto);

 if (SUBE == 0){
 Velo1 += 10;
 if(Velo1 >= 255){
 Velo1 = 255;
 }
 PWM1_Set_Duty(Velo1);
 Delay_ms(250);
 }else {
 if (BAJA == 0){
 Velo1 -= 10;
 if(Velo1 <= 0){
 Velo1 = 0;
 }
 PWM1_Set_Duty(Velo1);
 Delay_ms(250);
 }
 }

 }

}
