.MODEL SMALL
.DATA
A DB 08H,04H,09H,12H
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
      MOV AL,A[SI]
      INC SI
      CMP AL,A[SI]
      JNB MSG
      XCHG AL,A[SI]
      MOV A[SI-1],AL
   MSG:
      DEC CH
      JNZ INNERLOOP
      DEC CL
      JNZ OUTERLOOP
      MOV AH,4CH
      INT 21H
      END

      

  
