;move two numbers to register, add constant to value at memory location, store result at a memory loaction

MOV AX, 2000H
MOV DS, AX          ; move base adress
MOV BX, [0500H]
MOV CX, BX
ADD [0600H], 05h    ; add constant value
MOV DX,[0600H]      
MOV [0700H], DX     ; mov value to memory
