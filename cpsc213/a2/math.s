.pos 0x100
		ld $a, r0			#r0 = addr a
		ld $b, r1			#r1 = addr b
		ld (r0), r2			#r2 = a
		ld (r1), r3			#r3 = b
		ld $0x1, r4			#r4 = 1
		ld $0x4, r5			#r5 = 4
		add r3, r4			#r4 = b + 1
		add r5, r4			#r4 = (b + 1) + 4
		shr $0x1, r4		#r4 =(((b + 1) + 4) / 2)
		and r3, r4			#r4 = (((b + 1) + 4) / 2) & b
		shl $0x2, r4		#r4 = (((b + 1) + 4) / 2 )& b) << 2
		st  r4, 0x0(r0)		#a = r4
		halt
.pos0x2000
a:		.long 0x00000001	#a
b:		.long 0x00000001	#b