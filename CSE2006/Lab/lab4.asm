data segment
list dw 3333h,2222h,1111h,5555h,6666h
data ends
code segment
ASSUME CS: CODE, ds:data
START: MOV AX, data
mov ds,ax
mov dl, 0004H
DEC dl
UP1: mov cl,03h
mov si, offset list
UP: mov ax,[si]
INC SI
inc si
CMP AX, [SI]
JC DOWN
XCHG AX, [SI]
DEC SI
dec si
MOV [SI], AX
INC SI
inc si
DOWN: DEC CL
JNZ UP
DEC dl
JNZ UP1

hlt
code ends
end
