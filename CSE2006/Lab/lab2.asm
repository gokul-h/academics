code segment
assume cs:code
start:
mov ax, 1010H
mov bx, 0005H
add ax,bx
hlt
code ends
end start

