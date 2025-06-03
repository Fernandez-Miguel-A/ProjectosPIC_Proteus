#include "stdint.h"
#include <ctype.h>
#include "string.h"


uint8_t segment[10]={  //125
63,6,91,79,102,109,125,7,127,103
};
 
char keypadPort at PORTD;   
     
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


int res_=0;
uint8_t retardo = 100; // en 'msecs'
char retardo_s[5];

enum teclado_estado {E1, E2, E3, E4, Efin};
uint8_t estado_teclado= E1;

#define    LED1    RC6_bit  
#define    LED2    RC7_bit

int8_t atoi(char c)
{
        if (isdigit(c)){
           return c-48;
        }else
             return -1;
}

void main()
{
    int i, j;
    char c, tecla= ' ';
    uint8_t kp;
    
    //TRISA = 0xff;            // teclado       // Configure PORTB pins as salidas
    //TRISB = 0;
    TRISC = 0;            //LCD LCD-cmd
    
    ADCON1 |= 0x0f;      // PINES HABILITADOS COMO DIGITALES
//    ADCON0 |= 0x0f;      // PINES HABILITADOS COMO DIGITALES
//    ADCON2 
//    EECON1 |= 0XF;
//    CMCON  |= 0x7;
    
    PORTC = 0;
//    PORTA = 0xFF;
              
    Keypad_Init();
    
    Lcd_Init();                        // Initialize Lcd
    Delay_ms(15);
    
    Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    
    
    Lcd_Out(1,1,txt3);                 // Write text in first row                               
    Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
               
    while (1){        
        c = '0';  
        //Lcd_Chr(1,11,c);
//        Lcd_Out(1,9,c);        RC7_bit

        do {  
           kp = Keypad_Key_Press();
           if(!isdigit(c)){// && (atoi(c)>9)){
                 c = '0'; 
           }
           Lcd_Chr(1,11,c++);
           
            LED1 = 1;
            Delay_ms(500);     //retardo
            LED1 = 0;         
            Delay_ms(500);     //retardo
        } while(!kp);
         
        LED2 = 1;
        Delay_ms(500);     //retardo
        LED2 = 0;           
        Delay_ms(500);     //retardo
        
        switch (kp) {
          //case 10: kp = 42; break;  // '*'   // Uncomment this block for keypad4x3
          //case 11: kp = 48; break;  // '0'   
          //case 12: kp = 35; break;  // '#'
          //default: kp += 48;
                                            
          case  1: c = 55; break; // 7
          case  2: c = 56; break; // 8
          case  3: c = 57; break; // 9
          case  4: c = '%'; break; // A
          case  5: c = 52; break; // 4
          case  6: c = 53; break; // 5
          case  7: c = 54; break; // 6
          case  8: c = '*'; break; // B
          case  9: c = 49; break; // 1        // Uncomment this block for keypad4x4
          case 10: c = 50; break; // 2
          case 11: c = 51; break; // 3
          case 12: c = '-'; break; // C
          case 13: c = 'C'; break; // *
          case 14: c = 48; break; // 0
          case 15: c = '='; break; // #
          case 16: c = '+'; break; // D

        }       
        
           Lcd_Chr(1,9,c);

        tecla = c;
        switch(estado_teclado){
            case E1: retardo_s[0] = tecla;
                     Lcd_Chr(1,11,tecla);
                     Delay_ms(400);
                     break;          
            case E2: retardo_s[1] = tecla;
                     Lcd_Chr(1,12,tecla);
                     Delay_ms(400); 
                     break;
            case E3: retardo_s[2] = tecla;
                     Lcd_Chr(1,13,tecla);
                     Delay_ms(400);
                     break;
            case E4: retardo_s[3] = tecla;
                     Lcd_Chr(1,14,tecla);
                     Delay_ms(400);
                     break;
            case Efin:
                     Lcd_Out(1,11, "    ");
                     Delay_ms(600);
                     break;
        }    
        
        LED2 = 1;
        Delay_ms(500);     //retardo
        LED2 = 0;       
        Delay_ms(500);     //retardo
    }

}