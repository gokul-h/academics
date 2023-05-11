code segment
assume cs:code
start:
mov al, 04h
mov bl, 02h
div bl
hlt
code ends
end start

