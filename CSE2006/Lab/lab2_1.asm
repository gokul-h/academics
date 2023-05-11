data segment
array db 05h, 61h, 0Fh, 10h, 23h
data ends
code segment
assume cs:code,ds:data
start:
mov ax, data
mov ds, ax
rpt: add al,array[si]
inc si
loop rpt
hlt
code ends
end start
