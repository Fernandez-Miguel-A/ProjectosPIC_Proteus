#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"



uint8_t segment[10]={
63,6,91,79,102,109,125,7,127,103
};



void main()
{
     uint8_t i,j;
     TRISD = 0x00;
     
     while (1){
           PORTD = 0x00;
           Delay_ms(1000);
           
           /*
           PORTD = 0b00000001;        // 1  led
           Delay_ms(1000);
           
           PORTD = 0b00000010;        // 2  led
           Delay_ms(1000); 
           
           PORTD = 0b00000100;        // 3  led
           Delay_ms(1000);
           
           PORTD = 0b00001000;        // 4  led
           Delay_ms(1000);
           
           PORTD = 0b00010000;        // 5  led
           Delay_ms(1000);
           
           PORTD = 0b00100000;        // 6  led
           Delay_ms(1000);
           
           PORTD = 0b01000000;        // 7  led
           Delay_ms(1000);
           
           PORTD = 0b10000000;        // 8  led
           Delay_ms(1000);
           */   
           i = 0;                     
           for(; i< 8; i++){
               PORTD = 1<<i;         // 'i'  led
               Delay_ms(1000);  
           }
           j = 0;                     
           for(; j< 10; j++){
               PORTD = segment[j];         // 'i'  led
               Delay_ms(1000);  
           }
           // El 7segmentos tradicional falla en algunos ensayos. Debo usar el de
           //    pines mas angosto.
     }
}