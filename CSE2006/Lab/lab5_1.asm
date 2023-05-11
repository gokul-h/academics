; combination
assume cs:code,ds:data
data segment
	org 1000h
	n equ 08h
	r equ 02h
	temp dw ?	
	npr dw ?
	ncr dw ?
data ends
code segment
	start:
	mov ax,data
	mov ds,ax
	xor ax,ax
	xor dx,dx		
	mov bx,n-r
	call fact
	mov temp,ax
	xor ax,ax
	lp2:mov bx,n
	call fact
	mov bx,temp
	div bx			
	mov npr,ax
	mov bx,r
	call fact
	mov temp,ax
	mov ax,npr
	div temp
	mov ncr,ax
	mov bx,npr
	hlt
	fact proc
		cmp bx,01h
		jnz cnt
		mov ax,01h
		ret
		cnt:
		mov ax,01h
		mov cx,00h
		mov cx,bx
		dec cx
		mov ax, bx
		proc_lp: dec bx
		mul bx
		loop proc_lp
		ret
	fact endp
code ends
end start


