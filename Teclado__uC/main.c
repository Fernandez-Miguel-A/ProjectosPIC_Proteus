#include "stdint.h"
#include <ctype.h>
#include "string.h"
#include "keypad_X2.h"
#include "keypad_X3.h"


uint8_t segment[10]={  //125
63,6,91,79,102,109,125,7,127,103
};
 
//char keypadPort at PORTD;
     
// Lcd module connections
sbit LCD_RS at RB4_bit;   //PORTDbits.RD4    //LATD4_bit   //LATDbits.LATD4     //PORTD //LATD
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;
                      
sbit LCD_RS_Direction at TRISB4_bit;   // TRISBbits.RD4    //TRISB
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;


char txt3[] = "Lcd4bit:";
char texto[] = "VIEJO PIC16F877A";     // Usando 'const' No muestra el texto
char Txt[20];


int retardo = 500; // en 'msecs' .0-> 65535
char retardo_s[5];

enum teclado_estado {E1, E2, E3, E4, Efin};
uint8_t estado_teclado= E1;
volatile uint16_t timer1_ticks = 0, timer1_ticks2 = 0;
volatile uint16_t timer_50ms_ticks = 0;

#define    LED1    RB6_bit  
#define    LED2    RB7_bit  
#define    but    RE0_bit

void Timer_retardo_ms(void)
{
    LED1 = !LED1;
}
void Timer_50ms(void)
{
    LED2 = !LED2;
}

/*
int8_t atoi(char c)
{
    if (isdigit(c)){
       return c-48;
    }else
         return -1;
}


int StrToInt(char *s)
{
    int i=0, sal=0;
    while(s[i]!=0){
        sal = sal*10 + (s[i++]-48);   
    }
    return sal;
}*/
char Keypad_Get_Char(void)
{
    char c, tecla;
//    c = Keypad_Key_Click();
    switch (c) {                                                                                
        case  1: tecla = 55; break; // 7
        case  2: tecla = 56; break; // 8
        case  3: tecla = 57; break; // 9
        case  4: tecla = '%'; break; // A
        case  5: tecla = 52; break; // 4
        case  6: tecla = 53; break; // 5
        case  7: tecla = 54; break; // 6
        case  8: tecla = '*'; break; // B
        case  9: tecla = 49; break; // 1        // Uncomment this block for keypad4x4
        case 10: tecla = 50; break; // 2
        case 11: tecla = 51; break; // 3
        case 12: tecla = '-'; break; // C
        case 13: tecla = 'C'; break; // *
        case 14: tecla = 48; break; // 0
        case 15: tecla = '='; break; // #
        case 16: tecla = '+'; break; // D
        default: tecla = 0;                                                                                        //Unico valor al parecer es:  0
    }       
    return tecla;
}


#define    HAL_Delay(x)    Delay_ms(x)

void Retardo_ms(int n)
{
     int i;
     for(i=0; i<n; i++){
         Delay_1ms();
     }
}


void destellar() iv 0x0004 ics ICS_AUTO
{
    if (TMR1IF_bit) {
        TMR1H = 0xFD;
        TMR1L = 0x8F;   // 1 ms a 20 MHz, prescaler 1:8
        TMR1IF_bit = 0;

        timer1_ticks++;
        timer1_ticks2++;
        if (timer1_ticks >= 50) {
            timer1_ticks = 0;
            Timer_50ms();

            /*
            timer_50ms_ticks++;
            if (timer_50ms_ticks >= 10) {
                timer_50ms_ticks = 0;
                Timer_500ms();
            }*/
        }
        if (timer1_ticks2 >= retardo) {
            timer1_ticks2 = 0;
            Timer_retardo_ms();
        }
    }
}

void main()
{
    int i, j;
    char c, tecla;
    
    TRISB6_bit = 0;            //LED1
    TRISB7_bit = 0;            //LED2

    TRISE0_bit = 1;               //boton

    ADCON1 |= 0x0f;      // PINES HABILITADOS COMO DIGITALES
//    ADCON0 |= 0x0f;      // PINES HABILITADOS COMO DIGITALES
//    ADCON2 
//    EECON1 |= 0XF;
//    CMCON  |= 0x7;
    
    RB6_bit = 0;
    RB7_bit = 0;
    
    // Timer1:
    T1CON = 0x00;
    TMR1H = 0xFD;
    TMR1L = 0x8F;
    TMR1IF_bit = 0;
    TMR1IE_bit = 1;
    PEIE_bit = 1;
    GIE_bit = 1;
    T1CON = 0x31;   // Timer1 encendido: interrupción de 1 ms, reloj interno, prescaler 1:8
    // end:_
    
    //*Keypad_Init();
    
    Lcd_Init();                        // Initialize Lcd
    Delay_ms(15);                      // aguarda a que el Lcd se estabilice
    
    Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    
    
    Lcd_Out(1,1,txt3);                 // Write text in first row                               
    Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
    c = '0';
    while (1){
             
        
        do {  
           tecla = tecla_deco();
           if(!isdigit(c)){// && (atoi(c)>9)){
                 c = '0';
           }
           Lcd_Chr(1,15, tecla);
           Lcd_Chr(1,16,c++);


           if (but == 0){
              Lcd_Out(2,1,"                ");
              IntToStr(retardo, Txt);
              Lcd_Out(2,1,Txt);
           }
           //: modif retardo aqui Retardo_ms(retardo);
           //retardo = 500;
        } while(!tecla);

        // Retardo 50 ms

        if(tecla == '='){
            if(retardo_s[0] != 0)
                retardo = StrToInt(retardo_s);

        }
        if(!isdigit(tecla)){
            estado_teclado = Efin;
        }

        switch(estado_teclado){
            case E1: retardo_s[0] = tecla;
                     retardo_s[1] = 0;
                     Lcd_Chr(1,11,tecla);
                     estado_teclado = E2;
                     break;          
            case E2: retardo_s[1] = tecla; 
                     retardo_s[2] = 0;
                     Lcd_Chr(1,12,tecla); 
                     estado_teclado = E3;
                     break;
            case E3: retardo_s[2] = tecla;
                     retardo_s[3] = 0;
                     Lcd_Chr(1,13,tecla); 
                     estado_teclado = E4;
                     break;
            case E4: retardo_s[3] = tecla;
                     retardo_s[4] = 0;
                     Lcd_Chr(1,14,tecla);
                     estado_teclado = Efin;
                     break;
            case Efin:
                     Lcd_Out(1,11, "    ");
                     //retardo = StrToInt(retardo_s); 
                     retardo_s[0] = 0;
                     estado_teclado = E1;
                     break;
            default:
                    estado_teclado = E1;
                    break;
        }
        
//        Lcd_Out(2, 9, retardo_s);   
        
    }

}