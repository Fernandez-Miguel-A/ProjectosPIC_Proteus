#line 1 "C:/Users/FernandezMiguelA/Documents/STM32/7segmentos/main.c"









void main()
{
 int i, j;

 TRISC= 0;
 TRISD= 0;

 while (1){
  PORTC=0b00000000 ;
  PORTD  = 118;
  RC0_bit  = 1;
 Delay_ms(5);

  PORTC=0b00000000 ;
  PORTD  = 63;
  RC1_bit  = 1;
 Delay_ms(5);

  PORTC=0b00000000 ;
  PORTD  = 56;
  RC2_bit  = 1;
 Delay_ms(5);

  PORTC=0b00000000 ;
  PORTD  = 119;
  RC3_bit  = 1;
 Delay_ms(5);
 }

}
