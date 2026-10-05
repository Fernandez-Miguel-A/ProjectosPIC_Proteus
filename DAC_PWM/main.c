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


// info
//Declaración de constantes
//para la señal seno.
const unsigned short Seno[20] =
{
127, 146, 163, 177, 185, 189, 185,
177, 163, 146, 127, 107, 90, 76,
68, 65, 68, 76, 90, 107
};


/*
void main() {
    unsigned short i = 0;

    // 1. Configurar pines como salidas digitales
    TRISC2_bit = 0;       // RC2 es la salida física habitual para PWM1 en muchos PICs (ej. PIC16F887)

    // 2. Inicializar el módulo PWM1 a una frecuencia alta (ej. 5 kHz)
    // Una frecuencia alta facilita el filtrado RC.
    PWM1_Init(1563*10);

    // 3. Iniciar el módulo PWM1
    PWM1_Start();

    while (1) {
        // Generar una rampa ascendente de voltaje
        // El ciclo de trabajo (Duty Cycle) va de 0 (0V) a 255 (5V)
        for (i = 0; i < 255; i++) {
            PWM1_Set_Duty(i);  // Cambia el valor analógico de salida
            Delay_us(10);      // Controla la velocidad de la rampa
        }

        // Generar una rampa descendente de voltaje
        for (i = 255; i > 0; i--) {
            PWM1_Set_Duty(i);
            Delay_us(10);
        }
    }
}
*/
void main()
{
    int i, j;
    //Declaración de variables.
    unsigned short n=0;
    
    ADCON1 |= 0x0F;          //PUERTOS DIGITALES
   /* ADCON0 = 0;
    ADCON2 = 0; */
    
    CMCON |= 0x07;           // COMPARADORES COMO ENTRADAS DIGITALES 
    
    TRISB = 0;                        // Configure PORTB pins como salida
    TRISB6_bit = 1;         // Entrada de pulsadores
    TRISB7_bit = 1;         //   
    
    TRISC2_bit = 0;         //Salida PWM1
    
      
    //F_pwm >= 10*F_c
    PWM1_Init(1563*10);        // 1/(2*3.14159*7200*(10e-9)*math.sqrt(2))
     
    //PWM1_Set_Duty(0);// 0 -> 255.  255 es 100%
    
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
        
        //Bucle para recorres las 20 muestras
        //de un ciclo para la onda seno.
        //PWM1_Set_Duty(Seno[0]);
        for( n=0; n<20; n++ ){
            //Cambio del ciclo útil del PWM.
            PWM1_Set_Duty( Seno[n] );
            //Retardo de 50u seg.
            delay_ms(5);
        }
                       
    }

}