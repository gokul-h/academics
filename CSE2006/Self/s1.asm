; add two data
MOV AX, 2000H   ; base adress is loaded to ax and the transferred to ds as direct transfer is not allowded
MOV DS,AX
MOV AX, [500H]  ; move first value to ax register, physical adress = ds*10 + offset
ADD AX, [600h]  ; add with second value at location offset-600h
MOV [700H], AX  ; move the result to 700h [] means value at
HLT