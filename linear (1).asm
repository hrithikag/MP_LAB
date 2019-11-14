.MODEL SMALL
        DISPLAY MACRO MSG
        LEA DX,MSG
        MOV AH,09H
        INT 21h
        ENDM
.DATA
        LIST DB 01H,03H,05H,07H 
        N EQU ($-LIST)
        KEY DB 04H
        MSGS DB 0DH,0AH,"ELEMENT FOUND!$"
        MSGF DB 0DH,0AH,"ELEMENT NOT FOUND!$"
.CODE
START:  MOV AX,@DATA
        MOV DS,AX
        MOV CL,00H;
        MOV CH,N-1
AGAIN:  CMP CL,N-1
        JE NEXT
        JNC FAILED
NEXT:   MOV SI, OFFSET LIST
       XOR AH,AH
        MOV AL,CL
        MOV BP,AX
        MOV AL,DS:[BP][SI]
        CMP AL,KEY
        JE SUCCESS
        INC CL
        JMP AGAIN
SUCCESS:DISPLAY MSGS
        JMP FINAL
FAILED: DISPLAY MSGF
FINAL:  MOV AH,4CH
INT 21H
END
        
      
