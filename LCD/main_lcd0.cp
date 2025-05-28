#line 1 "C:/Users/FernandezMiguelA/Documents/STM32/LCD/main_lcd0.c"
#line 8 "C:/Users/FernandezMiguelA/Documents/STM32/LCD/main_lcd0.c"
sbit LCD_RS at LATD4_bit;
sbit LCD_EN at LATD5_bit;
sbit LCD_D4 at LATD0_bit;
sbit LCD_D5 at LATD1_bit;
sbit LCD_D6 at LATD2_bit;
sbit LCD_D7 at LATD3_bit;

sbit LCD_RS_Direction at TRISD4_bit;
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;


char txt3[] = "Lcd4bit";

void Move_Delay() {
 Delay_ms(500);
}

void main()
{
 int i, j;

 TRISD = 0;

 Lcd_Init();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1,6,txt3);

 Delay_ms(500);
 Lcd_Out(2,1,"PIC  es la onda!");


}
