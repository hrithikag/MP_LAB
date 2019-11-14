.MODEL SMALL
.DATA
A DW 77H,66H,22H,100H,80H
N EQU ($-A)
.CODE
    MOV AX,@DATA
    MOV DS,AX
    MOV CL,N
    DEC CL
    OUTERLOOP:
       MOV CH,CL
       MOV SI,00
    INNERLOOP:
       MOV AX,A[SI]
       ADD SI,02H
       CMP AX,A[SI]
       JB NOXG
       XCHG AX,A[SI]
       MOV A[SI-2],AX
    NOXG:
       DEC CH
       JNZ INNERLOOP
       DEC CL
       JNZ OUTERLOOP
       MOV AH,4CH
       INT 21H
       END
