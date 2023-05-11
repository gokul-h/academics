data segment
n1 dw 000Ah
n2 dw 0004h
gcd dw ?
lcm dw ?
data ends
assume cs:code,ds:data
code segment
start:
mov ax,data
mov ds,ax
mov ax,n1
mov bx,n2
compare:
cmp ax,bx
je ans
jb swap
division:
mov dx,0000h
div bx
cmp dx,0000h
je ans
mov ax,dx
jmp compare
swap:
xchg ax,bx
jmp division
ans:
mov gcd,bx
mov ax,n1
mov bx,n2
mul bx
div gcd
mov lcm,ax
mov ah,4ch
hlt
code ends
end start
