.pos 0x100
                 ld   $i, r0              # r0 = addr i
                 ld   $0x3, r1            # r1 = 3
                 ld   $a, r2              # r2 = addr a
                 ld   (r2, r1, 4), r3     # r3 = a[3]
                 st   r3, 0x0(r0)         # i = a[3]
                 ld   0x0(r0), r4         # r4 = val i
                 ld   (r2, r4, 4), r2     # r2 = a[i]
                 st   r2, 0x0(r0)         # i = a[i]
                 ld   $p, r0              # r0 = addr p
                 ld   $j, r1              # r1 = addr j
                 st   r1, 0x0(r0)         # p = &j
                 ld   $0x4, r3            # r3 = 4
                 st   r3, 0x0(r1)         # j = 4 (*p = 4)
                 ld   $0x2, r4            # r4 = 2
				 ld   $a, r5              # r5 = addr a
                 ld   (r5, r4, 4), r4     # r4 = a[2]
                 shl  $2, r4              # r4 = a[2] * 4
                 
                 add  r5, r4              # r4 = addr a + r4 (&a[a[2]])
				 st   r4, 0x0(r0)         # p = &a[a[2]]
				 
				 ld   0x0(r0), r6		  # r6 = &a[a[2]]
				 ld   0x0(r6), r6         # r6 = val a[a[2]]
				 ld   (r5, r3, 4), r7	  # r7 = a[4]
				 add  r6, r7    		  # r7 = a[4] + *p
				 st   r7, 0x0(r4)         # *p = *p + a[4]

                 halt                     
.pos 0x1000
i:               .long 0x0                # i
j:               .long 0x0                # j
p:               .long 0x1             # p (pointer)
.pos 0x2000
a:               .long 0x4                # a[0]
                 .long 0x0                # a[1]
                 .long 0x9                # a[2]
                 .long 0x8                # a[3]
                 .long 0x7                # a[4]
                 .long 0x6               # a[5]
                 .long 0x5                # a[6]
                 .long 0x4                # a[7]
                 .long 0x3                # a[8]
                 .long 0x2                # a[9]
