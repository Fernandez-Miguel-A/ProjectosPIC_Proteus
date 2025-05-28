#line 1 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/PWM_online/PWM_online.c"




sbit LCD_RS at RD0_bit;
sbit LCD_EN at RD1_bit;
sbit LCD_D4 at RD2_bit;
sbit LCD_D5 at RD3_bit;
sbit LCD_D6 at RD4_bit;
sbit LCD_D7 at RD5_bit;

sbit LCD_RS_Direction at TRISD0_bit;
sbit LCD_EN_Direction at TRISD1_bit;
sbit LCD_D4_Direction at TRISD2_bit;
sbit LCD_D5_Direction at TRISD3_bit;
sbit LCD_D6_Direction at TRISD4_bit;
sbit LCD_D7_Direction at TRISD5_bit;


sbit SUBE2 at RB6_bit;
sbit BAJA2 at RB7_bit;



sbit Giro1 at RB4_bit;
sbit Giro2 at RB5_bit;



sbit m11 at RB0_bit;
sbit m12 at RB1_bit;

sbit m21 at RB2_bit;
sbit m22 at RB3_bit;


unsigned int codigo, Velo1;
signed int Velo2 = 0;
unsigned char texto[16];




void derecha1()
{
 m11 = 1;
 m12 = 0;
}


void izquierda1()
{
 m11 = 0;
 m12 = 1;
}



void derecha2()
{
 m21 = 1;
 m22 = 0;
}


void izquierda2()
{
 m21 = 0;
 m22 = 1;
}



void main()
{
 ADCON1 = 0b1110;
 TRISA = 0b11111111;
 TRISB = 0;

 TRISB4_bit = 1;
 TRISB5_bit = 1;
 TRISB6_bit = 1;
 TRISB7_bit = 1;


 RC1_bit = 0;
 RC2_bit = 0;


 PWM1_Init(245);
 PWM2_Init(245);

 PWM1_Set_Duty(40);
 PWM2_Set_Duty(Velo2);


 PWM1_Start();
 PWM2_Start();

 ADC_Init();

 Lcd_Init();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 Lcd_Out(1,1, "V1=");
 Lcd_Out(2,1, "V2=");

 Lcd_Out(1,12, "G1=");
 Lcd_Out(2,12, "G2=");

 NOT_RBPU_bit = 0;


 while (1){

 codigo = ADC_Read(0);
 Velo1 = codigo*255.0/1023.0;
 PWM1_Set_Duty(Velo1);

 IntToStr(Velo1, texto);
 Lcd_Out(1,4, texto);

 if (SUBE2 == 0){
 Velo2 += 10;
 if(Velo2 >= 255){
 Velo2 = 255;
 }
 PWM2_Set_Duty(Velo2);
 Delay_ms(250);
 }else {
 if (BAJA2 == 0){
 Velo2 -= 10;
 if(Velo2 <= 0){
 Velo2 = 0;
 }
 PWM2_Set_Duty(Velo2);
 Delay_ms(250);
 }
 }

 IntToStr(Velo2, texto);
 Lcd_Out(2,4, texto);

 if (Giro1 == 0){
 derecha1();

 Lcd_Out(1,15, "D");

 }else {
 izquierda1();
 Lcd_Out(1,15, "I");
 }

 if(Giro2 == 0){
 derecha2();

 Lcd_Out(2,15, "D");
 }else {
 izquierda2();
 Lcd_Out(2,15, "I");
 }
#line 176 "C:/Users/FernandezMiguelA/Desktop/toDiffer/PIC/PWM_online/PWM_online.c"
 }
}
