
_main:

	MOVLW       15
	IORWF       ADCON1+0, 1 
	MOVLW       7
	IORWF       CMCON+0, 1 
	CLRF        TRISB+0 
	BSF         TRISB6_bit+0, BitPos(TRISB6_bit+0) 
	BSF         TRISB7_bit+0, BitPos(TRISB7_bit+0) 
	BCF         TRISC2_bit+0, BitPos(TRISC2_bit+0) 
	BSF         T2CON+0, 0, 0
	BCF         T2CON+0, 1, 0
	MOVLW       99
	MOVWF       PR2+0, 0
	CALL        _PWM1_Init+0, 0
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
	CALL        _PWM1_Start+0, 0
	CALL        _Lcd_Init+0, 0
	MOVLW       39
	MOVWF       R12, 0
	MOVLW       245
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 1
	BRA         L_main0
	DECFSZ      R12, 1, 1
	BRA         L_main0
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       6
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _txt3+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_txt3+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
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
L_main2:
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _texto+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_texto+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
	BTFSC       RB6_bit+0, BitPos(RB6_bit+0) 
	GOTO        L_main4
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
	MOVLW       255
	MOVWF       _Velo1+0 
	MOVLW       0
	MOVWF       _Velo1+1 
L_main5:
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
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
	GOTO        L_main7
L_main4:
	BTFSC       RB7_bit+0, BitPos(RB7_bit+0) 
	GOTO        L_main8
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
	CLRF        _Velo1+0 
	CLRF        _Velo1+1 
L_main9:
	MOVF        _Velo1+0, 0 
	MOVWF       FARG_PWM1_Set_Duty_new_duty+0 
	CALL        _PWM1_Set_Duty+0, 0
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
L_main8:
L_main7:
	GOTO        L_main2
L_end_main:
	GOTO        $+0
; end of _main
