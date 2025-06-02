#include "stdint.h"
#include <ctype.h>


uint8_t segment[10]={  //125
63,6,91,79,102,109,125,7,127,103
};
    
     
// Lcd module connections
sbit LCD_RS at RC4_bit;   //PORTDbits.RD4    //LATD4_bit   //LATDbits.LATD4     //PORTD //LATD
sbit LCD_EN at RC5_bit;
sbit LCD_D4 at RC0_bit;
sbit LCD_D5 at RC1_bit;
sbit LCD_D6 at RC2_bit;
sbit LCD_D7 at RC3_bit;
                      
sbit LCD_RS_Direction at TRISC4_bit;   // TRISDbits.RD4    //TRISD
sbit LCD_EN_Direction at TRISC5_bit;
sbit LCD_D4_Direction at TRISC0_bit;
sbit LCD_D5_Direction at TRISC1_bit;
sbit LCD_D6_Direction at TRISC2_bit;
sbit LCD_D7_Direction at TRISC3_bit;




char txt3[] = "Lcd4bit:";
char texto[] = "VIEJO PIC16F877A";     // Usando 'const' No muestra el texto
char Txt[20];

void main()
{
    int i, j;
    char c;
    
    TRISA = 0xff;            // teclado       // Configure PORTB pins as salidas
    //TRISB = 0;
    TRISC = 0;            //LCD LCD-cmd
    
    ADCON1 |= 0x06;      // PINES HABILITADOS COMO DIGITALES
    
    PORTC = 0;
       
    Lcd_Init();                        // Initialize Lcd
    Delay_ms(15);
    
    Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    
    Lcd_Out(1,1,txt3);                 // Write text in first row                               
    Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
               
    while (1){        
        c = '1';  
        Lcd_Chr(1,11,c);
//        Lcd_Out(1,9,c);
    }

}