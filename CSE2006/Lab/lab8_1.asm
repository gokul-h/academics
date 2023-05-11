data segment
data ends
code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,000Ah
mov bx,0004h
l1:cmp ax,bx
   je found
   cmp ax,bx
   jg skip
   xchg ax,bx
   skip:sub ax,bx
   jmp l1

found:

hlt
code ends
end start
