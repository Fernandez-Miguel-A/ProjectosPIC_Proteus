#include "stdint.h"



uint8_t segment[10]={  //125
63,6,91,79,102,109,125,7,127,103
};
    
     
// Lcd module connections
sbit LCD_RS at RD4_bit;   //PORTDbits.RD4    //LATD4_bit   //LATDbits.LATD4     //PORTD //LATD
sbit LCD_EN at RD5_bit;
sbit LCD_D4 at RA0_bit;
sbit LCD_D5 at RA1_bit;
sbit LCD_D6 at RA2_bit;
sbit LCD_D7 at RA3_bit;
                      
sbit LCD_RS_Direction at TRISD4_bit;   // TRISDbits.RD4    //TRISD
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISA0_bit;
sbit LCD_D5_Direction at TRISA1_bit;
sbit LCD_D6_Direction at TRISA2_bit;
sbit LCD_D7_Direction at TRISA3_bit;




char txt3[] = "Lcd4bit";
char texto[] = "VIEJO PIC16F877A";     // Usando 'const' No muestra el texto


void main()
{
    int i, j;
    
    TRISB = 0;            // 7-segm       // Configure PORTB pins as salidas
    TRISD = 0;            //LCD-cmd
    TRISA = 0;            //LCD
    
    ADCON1 |= 0x06;      // PINES HABILITADOS COMO DIGITALES
    PORTD = 0;
    PORTA = 0;
       
    Lcd_Init();                        // Initialize Lcd
    Delay_ms(15);
    
    Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    
    Lcd_Out(1,6,txt3);                 // Write text in first row                               
    Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
               
    while (1){
        Delay_ms(500);
             /*
        i=0;
        for(;i<=255; i++){
              PORTB=i;
              Delay_ms(1000);
        }      */
        
        i=0;
        for(;i<10; i++){
              PORTB=segment[i];  
              Delay_ms(100);
        }    
        // El 7segmentos tradicional falla en algunos ensayos. Debo usar el de
        //    pines mas angosto.     
        PORTB=62;
        //Delay_ms(8000);                                
        Lcd_Out(2, 1,(char *) texto);                 // Write text in first row  (char *) texto            
        Delay_ms(8000);
    }

}