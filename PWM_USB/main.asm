
_main:

;main.c,37 :: 		void main()
;main.c,41 :: 		ADCON1 |= 0x0F;          //PUERTOS DIGITALES
	MOVLW       15
	IORWF       ADCON1+0, 1 
;main.c,45 :: 		CMCON |= 0x07;           // COMPARADORES COMO ENTRADAS DIGITALES
	MOVLW       7
	IORWF       CMCON+0, 1 
;main.c,47 :: 		TRISB = 0;                        // Configure PORTB pins como salida
	CLRF        TRISB+0 
;main.c,48 :: 		TRISB6_bit = 1;         // Entrada de pulsadores
	BSF         TRISB6_bit+0, BitPos(TRISB6_bit+0) 
;main.c,49 :: 		TRISB7_bit = 1;         //
	BSF         TRISB7_bit+0, BitPos(TRISB7_bit+0) 
;main.c,51 :: 		TRISC2_bit = 0;         //Salida PWM1
	BCF         TRISC2_bit+0, BitPos(TRISC2_bit+0) 
;main.c,54 :: 		PWM1_Init(5000);
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
;main.c,56 :: 		PWM1_Set_Duty(Velo1);// 0 -> 255.  255 es 100%
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;main.c,59 :: 		PWM1_Start();
	CALL        _PWM1_Start+0, 0
;main.c,62 :: 		Lcd_Init();                        // Initialize Lcd
	CALL        _Lcd_Init+0, 0
;main.c,63 :: 		Delay_ms(15);
	MOVLW       39
	MOVWF       R12, 0
	MOVLW       245
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 1
	BRA         L_main0
	DECFSZ      R12, 1, 1
	BRA         L_main0
;main.c,65 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,66 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;main.c,69 :: 		Lcd_Out(1,1,txt3);                 // Write text in first row
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _txt3+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_txt3+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,70 :: 		Lcd_Out(2,1,"PIC  es la onda!");                 // Write text in first row
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?ICS?lstr1_main+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICS?lstr1_main+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICS?lstr1_main+0)
	MOVWF       TBLPTRU 
	MOVLW       ?lstr1_main+0
	MOVWF       FSR1 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       FSR1H 
	MOVLW       17
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
	MOVLW       ?lstr1_main+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_main+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,71 :: 		Delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main1:
	DECFSZ      R13, 1, 1
	BRA         L_main1
	DECFSZ      R12, 1, 1
	BRA         L_main1
	DECFSZ      R11, 1, 1
	BRA         L_main1
	NOP
	NOP
;main.c,73 :: 		IntToStr(Velo1, str);
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        _Velo1+1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _str+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_str+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;main.c,74 :: 		Lcd_Out(1,9, str);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       9
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _str+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_str+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,75 :: 		while (1){
L_main2:
;main.c,77 :: 		Lcd_Out(2, 1, texto);                 //  (char *) texto
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _texto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_texto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,79 :: 		if (SUBE == 0){
	BTFSC       RB6_bit+0, BitPos(RB6_bit+0) 
	GOTO        L_main4
;main.c,80 :: 		Velo1 += 10;
	MOVLW       10
	ADDWF       _Velo1+0, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      _Velo1+1, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       _Velo1+0 
	MOVF        R2, 0 
	MOVWF       _Velo1+1 
;main.c,81 :: 		if(Velo1 >= 255){
	MOVLW       128
	XORWF       R2, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main12
	MOVLW       255
	SUBWF       R1, 0 
L__main12:
	BTFSS       STATUS+0, 0 
	GOTO        L_main5
;main.c,82 :: 		Velo1 = 255;
	MOVLW       255
	MOVWF       _Velo1+0 
	MOVLW       0
	MOVWF       _Velo1+1 
;main.c,83 :: 		}
L_main5:
;main.c,84 :: 		PWM1_Set_Duty(Velo1);
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;main.c,85 :: 		IntToStr(Velo1, str);
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        _Velo1+1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _str+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_str+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;main.c,86 :: 		Lcd_Out(1,9, str);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       9
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _str+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_str+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,87 :: 		Delay_ms(250);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       138
	MOVWF       R12, 0
	MOVLW       85
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 1
	BRA         L_main6
	DECFSZ      R12, 1, 1
	BRA         L_main6
	DECFSZ      R11, 1, 1
	BRA         L_main6
	NOP
	NOP
;main.c,88 :: 		}else {
	GOTO        L_main7
L_main4:
;main.c,89 :: 		if (BAJA == 0){
	BTFSC       RB7_bit+0, BitPos(RB7_bit+0) 
	GOTO        L_main8
;main.c,90 :: 		Velo1 -= 10;
	MOVLW       10
	SUBWF       _Velo1+0, 0 
	MOVWF       R1 
	MOVLW       0
	SUBWFB      _Velo1+1, 0 
	MOVWF       R2 
	MOVF        R1, 0 
	MOVWF       _Velo1+0 
	MOVF        R2, 0 
	MOVWF       _Velo1+1 
;main.c,91 :: 		if(Velo1 <= 0){
	MOVLW       128
	MOVWF       R0 
	MOVLW       128
	XORWF       R2, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main13
	MOVF        R1, 0 
	SUBLW       0
L__main13:
	BTFSS       STATUS+0, 0 
	GOTO        L_main9
;main.c,92 :: 		Velo1 = 0;
	CLRF        _Velo1+0 
	CLRF        _Velo1+1 
;main.c,93 :: 		}
L_main9:
;main.c,94 :: 		PWM1_Set_Duty(Velo1);
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
;main.c,95 :: 		IntToStr(Velo1, str);
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVF        _Velo1+1, 0 
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       _str+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(_str+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
;main.c,96 :: 		Lcd_Out(1,9, str);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       9
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _str+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_str+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;main.c,97 :: 		Delay_ms(250);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       138
	MOVWF       R12, 0
	MOVLW       85
	MOVWF       R13, 0
L_main10:
	DECFSZ      R13, 1, 1
	BRA         L_main10
	DECFSZ      R12, 1, 1
	BRA         L_main10
	DECFSZ      R11, 1, 1
	BRA         L_main10
	NOP
	NOP
;main.c,98 :: 		}
L_main8:
;main.c,99 :: 		}
L_main7:
;main.c,101 :: 		}
	GOTO        L_main2
;main.c,103 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
