.pos 0x100
	ld $0x0, r0			# r0 = 0
	ld $tmp, r1			# r1 = addr of tmp
	st r0, (r1)			# tmp = 0
	ld $tos, r2			# r2 = addr of tos
	st r0, (r2)			# r2 = tos == 0
	ld (r2), r7			# r7 = val of tos
	
	ld $s, r3			# r3 = addr of s
	ld $a, r4			# r4 = addr of a
	ld 0(r4), r5		# r5 = a[0]
	st r5, (r3,r7,4)	# s[tos] = a[0]
	
	ld 4(r4), r5		# r5 = a[1]
	inc r7				# r7 = val tos++ == 1
	st r7, (r2)			# r2 == tos = r7 == val of tos
	st r5, (r3,r7,4)	# s[tos] = a[1]
	
	ld 8(r4), r5		# r5 = a[2]
	inc r7				# r7 = tos++ == 2
	st r7, (r2)			# r2 == tos = r7 == val tos
	st r5, (r3,r7,4)	# s[tos] = a[2]
	
	inc r7				# tos++
	st r7, (r2)
	dec r7				# tos--
	st r7, (r2)
	
	ld (r3, r7, 4), r5	# r5 = val of s[tos]
	st r5, (r1)			# tmp = s[tos]
	
	dec r7				# tos--
	st r7, (r2)
	ld (r3, r7, 4), r5	# r5 = val s[tos]
	ld (r1), r6			# r6 = val of tmp
	add r5, r6			# r6 = s[tos] + tmp
	st r6, (r1)			# tmp = r6
	
	dec r7				# tos--
	st r7, (r2)			
	ld (r3, r7, 4), r5	# r5 = val of s[tos]
	add r5, r6			# r6 = s[tos] + tmp
	st r6, (r1)			# tmp = r6
	
	halt


.pos 0x1000
tos:	.long 0			# tos
tmp:	.long 0			# tmp

.pos 0x2000
a:		.long 2			# a[0]
		.long 3			# a[1]
		.long 4			# a[2]
		
s:		.long 5			# s[0]
		.long 6			# s[1]
		.long 7			# s[2]
		.long 8			# s[3]
		.long 9			# s[4]
