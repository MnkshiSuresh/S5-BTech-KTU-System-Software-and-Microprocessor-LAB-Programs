0400: MOV AL,00H
0402: OUT 22H,AL
0404: MOV AL,02DH
0406: OUT 22H,AL
0408: MOV AL,90H
040A: OUT 22H,AL
040C: MOV BX,041E
040F: MOV SI,0
0412: MOV CX,7
0415: REP1: MOV  AL,[BX+SI]
0417: OUT 20H,AL
0419: INC SI
041A: LOOPNZ REP
