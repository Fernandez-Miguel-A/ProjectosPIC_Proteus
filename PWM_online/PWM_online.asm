
_derecha1:

	BSF        RB0_bit+0, BitPos(RB0_bit+0)
	BCF        RB1_bit+0, BitPos(RB1_bit+0)
L_end_derecha1:
	RETURN
; end of _derecha1

_izquierda1:

	BCF        RB0_bit+0, BitPos(RB0_bit+0)
	BSF        RB1_bit+0, BitPos(RB1_bit+0)
L_end_izquierda1:
	RETURN
; end of _izquierda1

_derecha2:

	BSF        RB2_bit+0, BitPos(RB2_bit+0)
	BCF        RB3_bit+0, BitPos(RB3_bit+0)
L_end_derecha2:
	RETURN
; end of _derecha2

_izquierda2:

	BCF        RB2_bit+0, BitPos(RB2_bit+0)
	BSF        RB3_bit+0, BitPos(RB3_bit+0)
L_end_izquierda2:
	RETURN
; end of _izquierda2

_main:

	MOVLW      14
	MOVWF      ADCON1+0
	MOVLW      255
	MOVWF      TRISA+0
	CLRF       TRISB+0
	BSF        TRISB4_bit+0, BitPos(TRISB4_bit+0)
	BSF        TRISB5_bit+0, BitPos(TRISB5_bit+0)
	BSF        TRISB6_bit+0, BitPos(TRISB6_bit+0)
	BSF        TRISB7_bit+0, BitPos(TRISB7_bit+0)
	BCF        RC1_bit+0, BitPos(RC1_bit+0)
	BCF        RC2_bit+0, BitPos(RC2_bit+0)
	BSF        T2CON+0, 0
	BSF        T2CON+0, 1
	MOVLW      255
	MOVWF      PR2+0
	CALL       _PWM1_Init+0
	BSF        T2CON+0, 0
	BSF        T2CON+0, 1
	MOVLW      255
	MOVWF      PR2+0
	CALL       _PWM2_Init+0
	MOVLW      40
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
	MOVF       _Velo2+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	CALL       _PWM1_Start+0
	CALL       _PWM2_Start+0
	CALL       _ADC_Init+0
	CALL       _Lcd_Init+0
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      86
	MOVWF      ?lstr1_PWM_online+0
	MOVLW      49
	MOVWF      ?lstr1_PWM_online+1
	MOVLW      61
	MOVWF      ?lstr1_PWM_online+2
	CLRF       ?lstr1_PWM_online+3
	MOVLW      ?lstr1_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      86
	MOVWF      ?lstr2_PWM_online+0
	MOVLW      50
	MOVWF      ?lstr2_PWM_online+1
	MOVLW      61
	MOVWF      ?lstr2_PWM_online+2
	CLRF       ?lstr2_PWM_online+3
	MOVLW      ?lstr2_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      12
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      71
	MOVWF      ?lstr3_PWM_online+0
	MOVLW      49
	MOVWF      ?lstr3_PWM_online+1
	MOVLW      61
	MOVWF      ?lstr3_PWM_online+2
	CLRF       ?lstr3_PWM_online+3
	MOVLW      ?lstr3_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      12
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      71
	MOVWF      ?lstr4_PWM_online+0
	MOVLW      50
	MOVWF      ?lstr4_PWM_online+1
	MOVLW      61
	MOVWF      ?lstr4_PWM_online+2
	CLRF       ?lstr4_PWM_online+3
	MOVLW      ?lstr4_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	BCF        NOT_RBPU_bit+0, BitPos(NOT_RBPU_bit+0)
L_main0:
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	MOVF       R0+0, 0
	MOVWF      _codigo+0
	MOVF       R0+1, 0
	MOVWF      _codigo+1
	CALL       _word2double+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      127
	MOVWF      R4+2
	MOVLW      134
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      192
	MOVWF      R4+1
	MOVLW      127
	MOVWF      R4+2
	MOVLW      136
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	CALL       _double2word+0
	MOVF       R0+0, 0
	MOVWF      _Velo1+0
	MOVF       R0+1, 0
	MOVWF      _Velo1+1
	MOVF       R0+0, 0
	MOVWF      FARG_PWM1_Set_Duty_new_duty+0
	CALL       _PWM1_Set_Duty+0
	MOVF       _Velo1+0, 0
	MOVWF      FARG_IntToStr_input+0
	MOVF       _Velo1+1, 0
	MOVWF      FARG_IntToStr_input+1
	MOVLW      _texto+0
	MOVWF      FARG_IntToStr_output+0
	CALL       _IntToStr+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      4
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _texto+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	BTFSC      RB6_bit+0, BitPos(RB6_bit+0)
	GOTO       L_main2
	MOVLW      10
	ADDWF      _Velo2+0, 0
	MOVWF      R1+0
	MOVF       _Velo2+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R1+1
	MOVF       R1+0, 0
	MOVWF      _Velo2+0
	MOVF       R1+1, 0
	MOVWF      _Velo2+1
	MOVLW      128
	XORWF      R1+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main18
	MOVLW      255
	SUBWF      R1+0, 0
L__main18:
	BTFSS      STATUS+0, 0
	GOTO       L_main3
	MOVLW      255
	MOVWF      _Velo2+0
	CLRF       _Velo2+1
L_main3:
	MOVF       _Velo2+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
	GOTO       L_main5
L_main2:
	BTFSC      RB7_bit+0, BitPos(RB7_bit+0)
	GOTO       L_main6
	MOVLW      10
	SUBWF      _Velo2+0, 0
	MOVWF      R1+0
	MOVLW      0
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _Velo2+1, 0
	MOVWF      R1+1
	MOVF       R1+0, 0
	MOVWF      _Velo2+0
	MOVF       R1+1, 0
	MOVWF      _Velo2+1
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      R1+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main19
	MOVF       R1+0, 0
	SUBLW      0
L__main19:
	BTFSS      STATUS+0, 0
	GOTO       L_main7
	CLRF       _Velo2+0
	CLRF       _Velo2+1
L_main7:
	MOVF       _Velo2+0, 0
	MOVWF      FARG_PWM2_Set_Duty_new_duty+0
	CALL       _PWM2_Set_Duty+0
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	DECFSZ     R11+0, 1
	GOTO       L_main8
	NOP
	NOP
L_main6:
L_main5:
	MOVF       _Velo2+0, 0
	MOVWF      FARG_IntToStr_input+0
	MOVF       _Velo2+1, 0
	MOVWF      FARG_IntToStr_input+1
	MOVLW      _texto+0
	MOVWF      FARG_IntToStr_output+0
	CALL       _IntToStr+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      4
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _texto+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	BTFSC      RB4_bit+0, BitPos(RB4_bit+0)
	GOTO       L_main9
	CALL       _derecha1+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      68
	MOVWF      ?lstr5_PWM_online+0
	CLRF       ?lstr5_PWM_online+1
	MOVLW      ?lstr5_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	GOTO       L_main10
L_main9:
	CALL       _izquierda1+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      73
	MOVWF      ?lstr6_PWM_online+0
	CLRF       ?lstr6_PWM_online+1
	MOVLW      ?lstr6_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
L_main10:
	BTFSC      RB5_bit+0, BitPos(RB5_bit+0)
	GOTO       L_main11
	CALL       _derecha2+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      68
	MOVWF      ?lstr7_PWM_online+0
	CLRF       ?lstr7_PWM_online+1
	MOVLW      ?lstr7_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
	GOTO       L_main12
L_main11:
	CALL       _izquierda2+0
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      15
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      73
	MOVWF      ?lstr8_PWM_online+0
	CLRF       ?lstr8_PWM_online+1
	MOVLW      ?lstr8_PWM_online+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
L_main12:
	GOTO       L_main0
L_end_main:
	GOTO       $+0
; end of _main
