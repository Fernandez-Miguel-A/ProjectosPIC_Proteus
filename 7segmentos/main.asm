
_main:

	CLRF        TRISC+0 
	CLRF        TRISD+0 
L_main0:
	CLRF        PORTC+0 
	MOVLW       118
	MOVWF       PORTD+0 
	BSF         RC0_bit+0, BitPos(RC0_bit+0) 
	MOVLW       33
	MOVWF       R12, 0
	MOVLW       118
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	NOP
	CLRF        PORTC+0 
	MOVLW       63
	MOVWF       PORTD+0 
	BSF         RC1_bit+0, BitPos(RC1_bit+0) 
	MOVLW       33
	MOVWF       R12, 0
	MOVLW       118
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	NOP
	CLRF        PORTC+0 
	MOVLW       56
	MOVWF       PORTD+0 
	BSF         RC2_bit+0, BitPos(RC2_bit+0) 
	MOVLW       33
	MOVWF       R12, 0
	MOVLW       118
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 1
	BRA         L_main4
	DECFSZ      R12, 1, 1
	BRA         L_main4
	NOP
	CLRF        PORTC+0 
	MOVLW       119
	MOVWF       PORTD+0 
	BSF         RC3_bit+0, BitPos(RC3_bit+0) 
	MOVLW       33
	MOVWF       R12, 0
	MOVLW       118
	MOVWF       R13, 0
L_main5:
	DECFSZ      R13, 1, 1
	BRA         L_main5
	DECFSZ      R12, 1, 1
	BRA         L_main5
	NOP
	GOTO        L_main0
L_end_main:
	GOTO        $+0
; end of _main
