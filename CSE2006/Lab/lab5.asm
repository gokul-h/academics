; factorial
CODE SEGMENT
    ASSUME CS:CODE 
    START:
        MOV CX,05H      ; number whose factorial has to be found (or) counter
        MOV AX,0001H    ; load 1
        MOV BX,AX      
    RPT:INC BX
        MUL BX          ; increment variable
        CMP BX,CX       ; if bx incremented till cx thi sevalutes to 0 (ZF=1)
        JNZ RPT         ; JNZ - if zero flag is not set then pass control to rpt
        HLT
CODE ENDS
    END START

