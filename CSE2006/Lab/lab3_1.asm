data segment 
array1 DW 0005h, 0024h, 0050h
array2 DW 0003h, 0012h, 0030h
resarr DW 3 DUP(0)
data ends

code segment
assume cs:code, ds:data
start:
mov cx, 03h
mov ax, Data
mov ds, ax
mov ax, 00h
lea si, array1
lea di, array2
lea bx, resarr

loop1:
mov ax,[si]
mov dx,[di]

sub ax,dx

mov [bx],ax
mov ax, 00h
add si, 02h
add di, 02h
add bx, 02h

loop loop1
hlt
code ends
end start
