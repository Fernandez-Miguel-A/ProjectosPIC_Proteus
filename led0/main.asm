
_main:

	CLRF        TRISD+0 
L_main0:
	CLRF        PORTD+0 
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	DECFSZ      R11, 1, 1
	BRA         L_main2
	NOP
	CLRF        R2 
L_main3:
	MOVLW       8
	SUBWF       R2, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_main4
	MOVF        R2, 0 
	MOVWF       R1 
	MOVLW       1
	MOVWF       R0 
	MOVF        R1, 0 
L__main12:
	BZ          L__main13
	RLCF        R0, 1 
	BCF         R0, 0 
	ADDLW       255
	GOTO        L__main12
L__main13:
	MOVF        R0, 0 
	MOVWF       PORTD+0 
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 1
	BRA         L_main6
	DECFSZ      R12, 1, 1
	BRA         L_main6
	DECFSZ      R11, 1, 1
	BRA         L_main6
	NOP
	INCF        R2, 1 
	GOTO        L_main3
L_main4:
	CLRF        R3 
L_main7:
	MOVLW       10
	SUBWF       R3, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_main8
	MOVLW       _segment+0
	MOVWF       FSR0 
	MOVLW       hi_addr(_segment+0)
	MOVWF       FSR0H 
	MOVF        R3, 0 
	ADDWF       FSR0, 1 
	BTFSC       STATUS+0, 0 
	INCF        FSR0H, 1 
	MOVF        POSTINC0+0, 0 
	MOVWF       PORTD+0 
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main10:
	DECFSZ      R13, 1, 1
	BRA         L_main10
	DECFSZ      R12, 1, 1
	BRA         L_main10
	DECFSZ      R11, 1, 1
	BRA         L_main10
	NOP
	INCF        R3, 1 
	GOTO        L_main7
L_main8:
	GOTO        L_main0
L_end_main:
	GOTO        $+0
; end of _main
