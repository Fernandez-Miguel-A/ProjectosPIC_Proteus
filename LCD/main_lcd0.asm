
_Move_Delay:

	MOVLW       13
	MOVWF       R11, 0
	MOVLW       175
	MOVWF       R12, 0
	MOVLW       182
	MOVWF       R13, 0
L_Move_Delay0:
	DECFSZ      R13, 1, 1
	BRA         L_Move_Delay0
	DECFSZ      R12, 1, 1
	BRA         L_Move_Delay0
	DECFSZ      R11, 1, 1
	BRA         L_Move_Delay0
	NOP
L_end_Move_Delay:
	RETURN      0
; end of _Move_Delay

_main:

	CLRF        TRISD+0 
	CALL        _Lcd_Init+0, 0
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
	MOVLW       13
	MOVWF       R11, 0
	MOVLW       175
	MOVWF       R12, 0
	MOVLW       182
	MOVWF       R13, 0
L_main1:
	DECFSZ      R13, 1, 1
	BRA         L_main1
	DECFSZ      R12, 1, 1
	BRA         L_main1
	DECFSZ      R11, 1, 1
	BRA         L_main1
	NOP
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?ICS?lstr1_main_lcd0+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICS?lstr1_main_lcd0+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICS?lstr1_main_lcd0+0)
	MOVWF       TBLPTRU 
	MOVLW       ?lstr1_main_lcd0+0
	MOVWF       FSR1 
	MOVLW       hi_addr(?lstr1_main_lcd0+0)
	MOVWF       FSR1H 
	MOVLW       17
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
	MOVLW       ?lstr1_main_lcd0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_main_lcd0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
L_end_main:
	GOTO        $+0
; end of _main
