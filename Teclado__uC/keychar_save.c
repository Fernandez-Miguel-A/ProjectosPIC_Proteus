char Keypad_Get_Char_copilot(void)
{
    uint8_t row, column;
    unsigned short column_mask;

    TRISD = 0x0F;
    PORTD = 0x00;

    for (row = 0; row < 4; row++) {
        PORTD = (uint8_t)(0x10u << row);

        for (column = 0; column < 4; column++) {
            column_mask = (unsigned short)(1u << column);
            if ((PORTD & column_mask) != 0) {
                Delay_ms(20);
                if ((PORTD & column_mask) != 0) {
                    val_key = keys[row][column];
                    PORTD = 0x00;
                    return val_key;
                }
            }
        }

        PORTD = 0x00;
    }

    val_key = 0;
    return val_key;