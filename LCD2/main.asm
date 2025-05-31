
_main:

;main.c,32 :: 		void main()
;main.c,36 :: 		TRISB = 0;            // 7-segm       // Configure PORTB pins as salidas
	CLRF       TRISB+0
;main.c,37 :: 		TRISD = 0;            //LCD-cmd
	CLRF       TRISD+0
;main.c,38 :: 		TRISA = 0;            //LCD
	CLRF       TRISA+0
;main.c,40 :: 		ADCON1 |= 0x06;      // PINES HABILITADOS COMO DIGITALES
	MOVLW      6
	IORWF      ADCON1+0, 1
;main.c,41 :: 		PORTD = 0;
	CLRF       PORTD+0
;main.c,42 :: 		PORTA = 0;
	CLRF       PORTA+0
;main.c,44 :: 		Lcd_Init();                        // Initialize Lcd
	CALL       _Lcd_Init+0
;main.c,45 :: 		Delay_ms(15);
	MOVLW      98
	MOVWF      R12+0
	MOVLW      101
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	NOP
	NOP
;main.c,47 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;main.c,48 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;main.c,50 :: 		Lcd_Out(1,6,txt3);                 // Write text in first row
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      6
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _txt3+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;main.c,51 :: 		Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
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
;main.c,53 :: 		while (1){
L_main1:
;main.c,54 :: 		Delay_ms(500);
	MOVLW      13
	MOVWF      R11+0
	MOVLW      175
	MOVWF      R12+0
	MOVLW      182
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
;main.c,62 :: 		i=0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
;main.c,63 :: 		for(;i<10; i++){
L_main4:
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main10
	MOVLW      10
	SUBWF      main_i_L0+0, 0
L__main10:
	BTFSC      STATUS+0, 0
	GOTO       L_main5
;main.c,64 :: 		PORTB=segment[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _segment+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;main.c,65 :: 		Delay_ms(100);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main7:
	DECFSZ     R13+0, 1
	GOTO       L_main7
	DECFSZ     R12+0, 1
	GOTO       L_main7
	DECFSZ     R11+0, 1
	GOTO       L_main7
	NOP
	NOP
;main.c,63 :: 		for(;i<10; i++){
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;main.c,66 :: 		}
	GOTO       L_main4
L_main5:
;main.c,69 :: 		PORTB=62;
	MOVLW      62
	MOVWF      PORTB+0
;main.c,71 :: 		Lcd_Out(2, 1,(char *) texto);                 // Write text in first row  (char *) texto
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _texto+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;main.c,72 :: 		Delay_ms(8000);
	MOVLW      203
	MOVWF      R11+0
	MOVLW      236
	MOVWF      R12+0
	MOVLW      132
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	DECFSZ     R11+0, 1
	GOTO       L_main8
	NOP
;main.c,73 :: 		}
	GOTO       L_main1
;main.c,75 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
