#include "stdint.h"

// Tabla de 16 muestras para un ciclo completo de seno (valores de 0 a 255, offset en 128)
const unsigned char seno[16] = {
    128, 177, 218, 245, 255, 245, 218, 177,
    128,  78,  37,  10,   0,  10,  37,  78
};

void main() {
    TRISD = 0x00; // Configura el Puerto B como salida digital para el DAC R-2R
    PORTD = 0;

    while(1) {
        int i;
        for(i = 0; i < 16; i++) {
            PORTD = seno[i];     // Envía el valor digital al arreglo R-2R
            Delay_us(50);       // Retardo para controlar la frecuencia de muestreo
        }
    }
}
/*
//Declaración de constantes
//para la señal seno.
const unsigned short Seno[20] =
{
127, 146, 163, 177, 185, 189, 185,
177, 163, 146, 127, 107, 90, 76,
68, 65, 68, 76, 90, 107
};
void main( void )
{
    //Declaración de variables.
    unsigned short n=0;
    //Configuración de puertos.
    TRISD = 0;
    PORTD = 127;
    while(1){ //Bucle infinito.
      //Bucle para recorres las 20 muestras
      //de un ciclo para la onda seno.
      for( n=0; n<20; n++ ){
          //Cambio de muestra en el puerto B.
          PORTD = Seno[n];
          //Retardo de 50u seg.
          delay_us(50);
      }
    }
}
*/
