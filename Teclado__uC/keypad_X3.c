#include "keypad_X3.h"
#include <stdbool.h>


//:_begin

uint8_t state_bit=state;


uint8_t t_tecla1()
{
    RD4_bit = !state_bit;//activa solo la fila 1
    RD5_bit = state_bit;
    RD6_bit = state_bit;
    RD7_bit = state_bit;

     if (te_c1==!state_bit   ) return(1);
     else if (te_c2==!state_bit) return(2);
     else if (te_c3==!state_bit) return(3);
    else if (te_c4==!state_bit) return(4);   //comentar si es 3*4
    else return(0);
}

uint8_t t_tecla2()
{
    RD4_bit = state_bit;
    RD5_bit = !state_bit;//activa solo la fila 2
    RD6_bit = state_bit;
    RD7_bit = state_bit;

     if (te_c1==!state_bit   ) return(5);
     else if (te_c2==!state_bit) return(6);
     else if (te_c3==!state_bit) return(7);
    else if (te_c4==!state_bit) return(8);   //comentar si es 3*4
    else return(0);
}


uint8_t t_tecla3()
{
    RD4_bit = state_bit;
    RD5_bit = state_bit;
    RD6_bit = !state_bit;//activa solo la fila 3
    RD7_bit = state_bit;

     if (te_c1==!state_bit   ) return(9);
     else if (te_c2==!state_bit) return(10);
     else if (te_c3==!state_bit) return(11);
    else if (te_c4==!state_bit) return(12);   //comentar si es 3*4
    else return(0);
}


uint8_t t_tecla4()
{
    RD4_bit = state_bit;
    RD5_bit = state_bit;
    RD6_bit = state_bit;
    RD7_bit = !state_bit;//activa solo la fila 4

     if (te_c1==!state_bit   ) return(13);
     else if (te_c2==!state_bit) return(14);
     else if (te_c3==!state_bit) return(15);
    else if (te_c4==!state_bit) return(16);   //comentar si es 3*4
    else return(0);
}


//Funcion para ver si hay una tecla presionada
uint8_t tecla_presionada()
{
  uint8_t te;

  te=t_tecla1();
  if (te!=0) return (te);
  Delay_ms(5);
  te=t_tecla2();
  if (te!=0) return (te);
  Delay_ms(5);
  te=t_tecla3();
  if (te!=0) return (te);
  Delay_ms(5);
  te=t_tecla4();
  if (te!=0) return (te);
  return 0;
}



//Función para decodificar el teclado.
uint8_t tecla_deco()
{
//Estructura switch case para evaluar los valores_ retornados
//por la librería del teclado.

    TRISD0_bit = 1;
    TRISD1_bit = 1;
    TRISD2_bit = 1;
    TRISD3_bit = 1;
    TRISD4_bit = 0;
    TRISD5_bit = 0;
    TRISD6_bit = 0;
    TRISD7_bit = 0;
  switch( tecla_presionada () )
  {
  case 1: return '7'; break;
  case 2: return '8'; break;
  case 3: return '9'; break;
  case 4: return '%'; break;
  case 5: return '4';  break;
  case 6: return '5'; break;
  case 7: return '6'; break;
  case 8: return '*'; break;
  case 9: return '1'; break;
  case 10: return '2'; break;
  case 11: return '3'; break;
  case 12: return '-'; break;
  case 13: return 'C';  break;
  case 14: return '0';  break;
  case 15: return '=';  break;
  case 16: return '+';  break;
  default: return 0; break; //Tecla no pulsada.
  }
}

//:_end