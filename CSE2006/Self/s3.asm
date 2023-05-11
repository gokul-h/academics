; Add content in 2000h:0500h with 3000h:0600h ansd store result in 5000h:0700h.
; contents are in different segments so it has be reinitalized before every access

MOV AX,2000H
MOV DS, AX
MOV AX, [500H]  ; get first variable
MOV CX,3000H
MOV DS, CX
MOV BX, [600H]  ; get second variable
ADD AX, BX      ; add values
MOV CX,2000H
MOV DS, CX
MOV [700H], AX  ; store in result
HLT