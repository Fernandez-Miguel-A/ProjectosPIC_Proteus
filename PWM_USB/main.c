#include "stdint.h"



uint8_t segment[10]={  //125
63,6,91,79,102,109,125,7,127,103
};
    
             
// Lcd module connections
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

int Velo1 = 50;              // 0 -> 255.


char txt3[] = "Lcd4bit:";
char str[20];
char texto[] = "NUEVO PIC18F2550";     // Usando 'const' No muestra el texto


void main()
{
    int i, j;
    
    ADCON1 |= 0x0F;          //PUERTOS DIGITALES
   /* ADCON0 = 0;
    ADCON2 = 0; */
    
    CMCON |= 0x07;           // COMPARADORES COMO ENTRADAS DIGITALES 
    
    TRISB = 0;                        // Configure PORTB pins como salida
    TRISB6_bit = 1;         // Entrada de pulsadores
    TRISB7_bit = 1;         //   
    
    TRISC2_bit = 0;         //Salida PWM1
    
      
    PWM1_Init(5000);
     
    PWM1_Set_Duty(Velo1);// 0 -> 255.  255 es 100% 
    
    // Arranco el PWM
    PWM1_Start(); 
     
     
    Lcd_Init();                        // Initialize Lcd
    Delay_ms(15);                   
    
    Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    
    
    Lcd_Out(1,1,txt3);                 // Write text in first row                               
    Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
    Delay_ms(500);

     IntToStr(Velo1, str);
     Lcd_Out(1,9, str);   
    while (1){
              
        Lcd_Out(2, 1, texto);                 //  (char *) texto            
        //Delay_ms(800);
        if (SUBE == 0){
           Velo1 += 10;
           if(Velo1 >= 255){
               Velo1 = 255;
           }
           PWM1_Set_Duty(Velo1);
           IntToStr(Velo1, str);
           Lcd_Out(1,9, str); 
           Delay_ms(250);  
        }else { 
           if (BAJA == 0){
               Velo1 -= 10;
               if(Velo1 <= 0){
                   Velo1 = 0;
               }
               PWM1_Set_Duty(Velo1);
               IntToStr(Velo1, str);
               Lcd_Out(1,9, str); 
               Delay_ms(250);  
           }
        }                
                       
    }

}