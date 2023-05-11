data segment
        ar dw 2h,5h,7h,19h,24h,56h,34h,58h,92h,55h
        ev equ 02h
        tot dw ?
        avg dw ?
data ends
code segment
        assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov cx,0ah
lea si,ar
mov dx,0h
xor ax,ax

loop1:
mov ax,ar[si]
mov dl,ev
div dl
cmp ah,0
jnz fail
mov dl,ev
mul dl
add bx,ar[si]
add si,02h
loop loop1
xor ax,ax
jmp endl

fail:
add si,02h
loop loop1

endl:
xor dx,dx
mov ax,bx
mov cx,06h
div cx
mov tot,bx
mov avg,ax

int 21h
code ends
end start