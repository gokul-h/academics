; and or xor not shl shr
; logical operations

DATA SEGMENT
	ELEMENTS DB 53H,44H
	ANDRES DB ?
	ORRES DB ?
	XORRES DB ?
	NOTRES DB ?
	SHLRES DB ?
	SHRRES DB ?
DATA ENDS

CODE SEGMENT
	ASSUME DS:DATA,CS:CODE
	START:
	MOV AX,DATA
	MOV DS,AX
	MOV AL,00H
	
	MOV AL,ELEMENTS[SI]
	MOV BL,ELEMENTS[SI+1]
	AND AL,BL	; converted to binary and perform bitwise operations
	MOV ANDRES,AL ; store result

	; load 'al' again since its value has changed
	MOV AL,ELEMENTS[SI]
	OR AL,BL
	MOV ORRES,AL;

	MOV AL,ELEMENTS[SI]
	XOR AL,BL
	MOV XORRES,AL;

	MOV AL,ELEMENTS[SI]
	NOT AL
	MOV NOTRES,AL;

	MOV AL,ELEMENTS[SI]
	MOV CL,01H
	SHL AL,CL ;cl denotes no of times to be shifted
	MOV SHLRES,AL

	MOV AL,ELEMENTS[SI]
	MOV CL,01H
	SHR AL,CL ;cl denotes no of times to be shifted
	MOV SHRRES,AL
CODE ENDS
	END START
	
	