0400: MOV AL,80   ;initialize mode
0402: OUT 46,AL   ;location of control word
0404: MOV CL,04   ;number of steps
0406: MOV BX,0500 ;location of data
0409: MOV AL,[BX] ;copy data to AL
040B: OUT 40,AL   ;to I/O port of 8255
040D: CALL 0415   ;calling delay prgrm
0410: INC BX      ;increment BX
0411: LOOPNZ 0409 ;loop when zero flag not set
0413: JMP 0404    ;repeat from setting counter
0415: PUSH CX     ;saving CX
0416: MOV CX,FFFF ;delay loop count
0419: LOOPNZ 0419 ;looping here when zero flag not set
041B: POP CX      ;retrieve CX
041C: RET         ;return
