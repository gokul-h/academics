; packed BCD to ASCII
; first unpack bcd to ah and al
; add 30 to both ah and al
CODE SEGMENT
	ASSUME CS:CODE
	START:
	MOV AL,24H
	MOV BL,10H
	DIV BL		;unpack
	ADD AL,30H
	ADD AH,30H
	XCHG AL,AH
	HLT
CODE ENDS
	END START