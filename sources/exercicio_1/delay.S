.global delay

delay:
	/* r0=delay */
	/* calculate nop's x delay */
	/* 14 740 000 nops por segundo*/
	/* Queremos em milisegundos, logo 14 740xR0*/
	/* 14 740 = 0x3994 */
	
	LDR R1, =0x3994
	MUL R1, R0, R1
loop:
	SUB R1, R1, #0x1
	CMP R1, #0x0
	BNE loop
return:
	MOV PC, LR


