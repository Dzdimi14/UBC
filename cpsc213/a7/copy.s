.pos 0x100
start:			ld $stackBtm, r5	# sp = addr of bottom of stack
				inca r5				# initialize sp
				gpc $0x6, r6		# r6 = ra
				j main				# call main()
				
				halt
				
.pos 0x200
main:			deca r5				# allocate callee frame
				st r6, (r5)			# save start ra to stack
				gpc $0x6, r6		# r6 = ra of main
				j copy				# call copy()
				inca r5				# deallocate callee frame
				ld (r5), r6
				j	(r6)			# return 
				
.pos 0x400
copy:			deca r5				# allocate callee frame
				st r6, (r5)			# save main ra to stack
				ld $0xfffffff4, r0	# size of caller frame = -12
				add r0, r5			# allocate space for local vars
				
				
				ld $src, r0			# r0 = &src[0]
				ld 0x8(r5), r1		# r1 = i
				
loop:			ld (r0, r1, 4), r3	# r3 = src[i]
				beq r3, end			# if src[i] == 0, goto end
				st r3, (r5, r1, 4)	# dst[i] = src[i]
				inc r1
				j loop
				

end:			ld $0x0, r0			# r0 = 0
				st r0, (r5, r1, 4)	# dst[i] = 0
				
				ld $0xc, r0			# r0 = 12 = size of caller frame
				add r0, r5
				ld (r5), r6
				j (r6)
				


.pos 0x2000
src:			.long 0x00000001
				.long 0x00000001
				.long 0x00000001
				.long 0x00002010
				.long 0x0000ffff
				.long 0xffff6001
				.long 0x60026003
				.long 0x60046005
				.long 0x60066007
				.long 0xff00f000
.pos 0x3000
stackTop:       .long 0x00000000
                .long 0x00000000         
                .long 0x00000000         
                .long 0x00000000         
                .long 0x00000000         
                .long 0x00000000       #dst[0]  
                .long 0x00000000       #dst[1]
                .long 0x00000000       #i  
                .long 0x00000000         
stackBtm:       .long 0x00000000