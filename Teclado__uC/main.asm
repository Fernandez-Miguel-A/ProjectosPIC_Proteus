
_main:

;main.c,32 :: 		void main()
;main.c,37 :: 		TRISA = 0xff;            // teclado       // Configure PORTB pins as salidas
	MOVLW      255
	MOVWF      TRISA+0
;main.c,39 :: 		TRISC = 0;            //LCD LCD-cmd
	CLRF       TRISC+0
;main.c,41 :: 		ADCON1 |= 0x06;      // PINES HABILITADOS COMO DIGITALES
	MOVLW      6
	IORWF      ADCON1+0, 1
;main.c,43 :: 		PORTC = 0;
	CLRF       PORTC+0
;main.c,45 :: 		Lcd_Init();                        // Initialize Lcd
	CALL       _Lcd_Init+0
;main.c,46 :: 		Delay_ms(15);
	MOVLW      39
	MOVWF      R12+0
	MOVLW      245
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
;main.c,48 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;main.c,49 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;main.c,51 :: 		Lcd_Out(1,1,txt3);                 // Write text in first row
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _txt3+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;main.c,52 :: 		Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      80
	MOVWF      ?lstr1_main+0
	MOVLW      73
	MOVWF      ?lstr1_main+1
	MOVLW      67
	MOVWF      ?lstr1_main+2
	MOVLW      32
	MOVWF      ?lstr1_main+3
	MOVLW      32
	MOVWF      ?lstr1_main+4
	MOVLW      101
	MOVWF      ?lstr1_main+5
	MOVLW      115
	MOVWF      ?lstr1_main+6
	MOVLW      32
	MOVWF      ?lstr1_main+7
	MOVLW      108
	MOVWF      ?lstr1_main+8
	MOVLW      97
	MOVWF      ?lstr1_main+9
	MOVLW      32
	MOVWF      ?lstr1_main+10
	MOVLW      111
	MOVWF      ?lstr1_main+11
	MOVLW      110
	MOVWF      ?lstr1_main+12
	MOVLW      100
	MOVWF      ?lstr1_main+13
	MOVLW      97
	MOVWF      ?lstr1_main+14
	MOVLW      33
	MOVWF      ?lstr1_main+15
	CLRF       ?lstr1_main+16
	MOVLW      ?lstr1_main+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;main.c,54 :: 		while (1){
L_main1:
;main.c,56 :: 		Lcd_Out(1,9,c);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      9
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      49
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;main.c,57 :: 		}
	GOTO       L_main1
;main.c,59 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
