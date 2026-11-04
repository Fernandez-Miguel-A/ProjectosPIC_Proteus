#include "keypad_X2.h"
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
