/*#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
*/

         
// Lcd module connections
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


const char figura_1[8] = {0x0A, 0x0A, 0x0A, 0x00, 0x11, 0x11, 0x0E, 0x00};
const char figura_2[8] = {0x0, 0x4, 0x2, 0x1f, 0x2, 0x4, 0x0, 0x00};

char txt3[] = "LCD key: ";
char Txt[20], buffer[50];

void Move_Delay() {                  // Function used for text moving
  Delay_ms(500);                     // You can change the moving speed here
}

void main()
{
    int i, j, v= 0;
    float t= 0.0;
    char c = 'M';
    
    TRISD = 0;                        // Configure PORTB pins as digital
   
    Lcd_Init();                        // Initialize Lcd
    Delay_ms(15);
    
   /*
    Lcd_CGRAM_Init();
    Lcd_CGRAM_CreateChar(0, figura_1);
    Lcd_CGRAM_CreateChar(1, figura_2);
    Lcd_CGRAM_Close();  */
    
    Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    
    Lcd_Out(1,1,txt3);                 // Write text in first row 
    Lcd_Out(2, 1, "PIC  es la onda!");                 // Write text in first row
    
    Delay_ms(1000);
    Lcd_Cmd(_LCD_CLEAR);
    sprintf(Txt, "  %0.2f     %c", 3.14159265, c);
    Lcd_Out(2, 1, Txt); 
    
    Lcd_Chr(1, 8, 'z');
    
    Delay_ms(1500);
    Lcd_Cmd(_LCD_CLEAR);
   
    while (1){
        Lcd_Out(1,1, "Test LCD 16x2");
        Lcd_Out(2,1, "PIC18F4620");
        Lcd_Chr(2,12, ' ');
        Lcd_Cmd(_LCD_BLINK_CURSOR_ON);
        Delay_ms(2000);
        Lcd_Cmd(_LCD_CURSOR_OFF);
        Lcd_Cmd(_LCD_CLEAR);
        Delay_ms(400);
        
        Lcd_Out(1,1, "CGRAM Caracteres");
        Lcd_Out(2,1, ":)->");
        //Lcd_Write_Char(0);
        //Lcd_Write_Char(1);
        Delay_ms(1500);
        Lcd_Cmd(_LCD_CLEAR);
        Delay_ms(400);
        
        Lcd_Out(1,1, "Hola a todos");
        Delay_ms(500);
        for(i=0; i<15; i++){
            Lcd_Cmd(_LCD_SHIFT_RIGHT);
            Delay_ms(300);
        }
        Delay_ms(300);
        for(i=0; i<15; i++){
            Lcd_Cmd(_LCD_SHIFT_LEFT);
            Delay_ms(300);
        }
        Lcd_Cmd(_LCD_CLEAR);
        Delay_ms(400);
        
        sprintf(buffer, "Int: %u", v);
        Lcd_Out(1,1, buffer);
        sprintf(buffer, "Float: %0.2f", t);  
        Lcd_Out(2,1, buffer);
        Delay_ms(1500);
        Lcd_Cmd(_LCD_CLEAR);
        Delay_ms(100);
    }

}



/*

// Lcd module connections
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
// End Lcd module connections

char txt1[] = "mikroElektronika";    
char txt2[] = "EasyPIC7";
char txt3[] = "Lcd4bit";
char txt4[] = "example";

char i;                              // Loop variable

void Move_Delay() {                  // Function used for text moving
  Delay_ms(500);                     // You can change the moving speed here
}

void main(){
  TRISD = 0;                        // Configure PORTB pins as digital
  
  Lcd_Init();                        // Initialize Lcd

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,6,txt3);                 // Write text in first row

  Lcd_Out(2,6,txt4);                 // Write text in second row
  Delay_ms(2000);
  Lcd_Cmd(_LCD_CLEAR);               // Clear display

  Lcd_Out(1,1,txt1);                 // Write text in first row
  Lcd_Out(2,5,txt2);                 // Write text in second row

  Delay_ms(2000);

  // Moving text
  for(i=0; i<4; i++) {               // Move text to the right 4 times
    Lcd_Cmd(_LCD_SHIFT_RIGHT);
    Move_Delay();
  }

  while(1) {                         // Endless loop
    for(i=0; i<8; i++) {             // Move text to the left 7 times
      Lcd_Cmd(_LCD_SHIFT_LEFT);
      Move_Delay();
    }

    for(i=0; i<8; i++) {             // Move text to the right 7 times
      Lcd_Cmd(_LCD_SHIFT_RIGHT);
      Move_Delay();
    }
  }
}


*/