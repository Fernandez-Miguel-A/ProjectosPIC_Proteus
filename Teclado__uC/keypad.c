#include "keypad.h"
#include <stdbool.h>

char val_key;
const char keys[4][4] = {{'7','8','9','%'},
                         {'4','5','6','*'},
                         {'1','2','3','-'},
                         {'C','0','=','+'}};


char Keypad_Get_Char_copilot(void)
{
    uint8_t row, column;
    unsigned short column_mask;

    TRISD = 0x0F;
    
    if (state == 0) {
       PORTD = 0x00;
    } else {
       PORTD = 0xF0;
    }

    for (row = 0; row < 4; row++) {
        if (state == 0) {
            PORTD = (uint8_t)(0x10 << row);
            // :-: HAL_GPIO_WritePin(let_PORTS[r], let_PINS[r], !state);
        } else {
            PORTD = (uint8_t)(0xF0 & ~(0x10 << row));
            // :-: HAL_GPIO_WritePin(let_PORTS[r], let_PINS[r], !state);
        }
        for (column = 0; column < 4; column++) {
            column_mask = (unsigned short)(1 << column);
            if (((PORTD & column_mask) != 0) != (state != 0)) {
                Delay_ms(4);
                while (((PORTD & column_mask) != 0) != (state != 0));
                Delay_ms(4);
                val_key = keys[row][column];

                //PORTD = 0x0000;// state
                if (state == 0) {
                    PORTD = 0x00;
                } else {
                    PORTD = 0xF0;
                }
                return val_key;

            }
        }

        if (state == 0) {
            PORTD = 0x00;
        } else {
            PORTD = 0xF0;
        }
    }

    val_key = 0;
    return val_key;
}


char Keypad_Get_Char_uC(void)
{
    uint8_t r, c;
    unsigned short column_mask;

    TRISD0_bit = 1;
    TRISD1_bit = 1;
    TRISD2_bit = 1;
    TRISD3_bit = 1;
    TRISD4_bit = 0;
    TRISD5_bit = 0;
    TRISD6_bit = 0;
    TRISD7_bit = 0;

    /*
    RD4_bit = 1;
    RD5_bit = 1;
    RD6_bit = 1;
    RD7_bit = 1;*/
    PORTD = 0xF0;

    val_key = 0;

    for (r = 0; r < 4; r++) {
        /*switch (r) {
            case 0: RD4_bit = 0; break;
            case 1: RD5_bit = 0; break;
            case 2: RD6_bit = 0; break;
            default: RD7_bit = 0; break;
        }*/

        for (c = 0; c < 4; c++) {
            column_mask = 0x01 << c;
            if ((PORTD & column_mask) == 1) {
                Delay_ms(4); //: begin. si elimino el retardo se me cuelga Proteus
                //while ((PORTD & column_mask) == 1);
                Delay_ms(4); //: end.
                val_key = keys[r][c];
                
                PORTD = 0xF0;
                return val_key;
            }
        }
        /*
        switch (r) {
            case 0: RD4_bit = 1; break;
            case 1: RD5_bit = 1; break;
            case 2: RD6_bit = 1; break;
            default: RD7_bit = 1; break;
        }*/
    }

    return val_key;
}

//:_begin

uint8_t res_=res;


uint8_t t_tecla1()
{
    RD4_bit = !res_;//activa solo la fila 1
    RD5_bit = res_;
    RD6_bit = res_;
    RD7_bit = res_;

     if (te_c1==!res_   ) return(1);
     else if (te_c2==!res_) return(2);
     else if (te_c3==!res_) return(3);
    else if (te_c4==!res_) return(4);   //comentar si es 3*4
    else return(0);
}

uint8_t t_tecla2()
{
    RD4_bit = res_;
    RD5_bit = !res_;//activa solo la fila 2
    RD6_bit = res_;
    RD7_bit = res_;

     if (te_c1==!res_   ) return(5);
     else if (te_c2==!res_) return(6);
     else if (te_c3==!res_) return(7);
    else if (te_c4==!res_) return(8);   //comentar si es 3*4
    else return(0);
}


uint8_t t_tecla3()
{
    RD4_bit = res_;
    RD5_bit = res_;
    RD6_bit = !res_;//activa solo la fila 3
    RD7_bit = res_;

     if (te_c1==!res_   ) return(9);
     else if (te_c2==!res_) return(10);
     else if (te_c3==!res_) return(11);
    else if (te_c4==!res_) return(12);   //comentar si es 3*4
    else return(0);
}


uint8_t t_tecla4()
{
    RD4_bit = res_;
    RD5_bit = res_;
    RD6_bit = res_;
    RD7_bit = !res_;//activa solo la fila 4

     if (te_c1==!res_   ) return(13);
     else if (te_c2==!res_) return(14);
     else if (te_c3==!res_) return(15);
    else if (te_c4==!res_) return(16);   //comentar si es 3*4
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