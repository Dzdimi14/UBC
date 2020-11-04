.pos 0x0
                 ld   $sb, r5			# sp = addr of last word of stack
                 inca r5				# sp = addr of word after stack
                 gpc  $6, r6            # r6 = ra = pc + 6
                 j    0x300             # call bar()
                 halt                     
.pos 0x100
                 .long 0x00001000         
.pos 0x200
                 ld   0x0(r5), r0		# load a0 from stack
                 ld   0x4(r5), r1       # load a1 from stack
                 ld   $0x100, r2        # r2 = addr of pointer p
                 ld   0x0(r2), r2       # r2 = dereference pointer = p* = &s[0]
                 ld   (r2, r1, 4), r3   # r3 = s[a0]
                 add  r3, r0            # r0 = a0 + s[a0]
                 st   r0, (r2, r1, 4)   # s[a0] = a0 + s[a0]
                 j    0x0(r6)           # return
.pos 0x300
                 ld   $0xfffffff4, r0	# r0 = -12 = -(size of callee part of bar's frame)
                 add  r0, r5            # allocate callee part of bar's frame
                 st   r6, 0x8(r5)       # store start's ra to stack
                 ld   $0x1, r0          # r0 = l0 = 1
                 st   r0, 0x0(r5)       # save val of l0 to stack (local var)
                 ld   $0x2, r0          # r0 = l1 = 2
                 st   r0, 0x4(r5)       # save val a1 to stack (local var)
                 ld   $0xfffffff8, r0	# r0 = -8 = -(size of caller part of foo's frame)
                 add  r0, r5            # allocate caller part of foo's frame
                 ld   $0x3, r0          # r0 = a0 = 3
                 st   r0, 0x0(r5)       # save val of a0 to stack (arg)
                 ld   $0x4, r0          # r0 = a1 = 4
                 st   r0, 0x4(r5)       # save val of a1 to stack (arg)
                 gpc  $6, r6			# r6 = set ra 
                 j    0x200				# foo(a0, a1)
                 ld   $0x8, r0          # size of caller part of foo's frame
                 add  r0, r5            # deallocate caller part of foo's frame
                 ld   0x0(r5), r1       # r1 = l0
                 ld   0x4(r5), r2       # r2 = l1
                 ld   $0xfffffff8, r0   # r0 = -8 = -(size of caller's part of foo's frame)
                 add  r0, r5            # allocate caller part of foo's frame
                 st   r1, 0x0(r5)       # a0 = l0
                 st   r2, 0x4(r5)       # a1 = l1
                 gpc  $6, r6			# r6 = ra of bar
                 j    0x200				# foo (l0, l1)
                 ld   $0x8, r0          # size of caller part of foo's frame
                 add  r0, r5            # deallocate caller part of foo's frame
                 ld   0x8(r5), r6       # r6 = ra of start
                 ld   $0xc, r0          # r0 = 12 = size of callee part of bar's frame
                 add  r0, r5            # deallocate callee part of bar's frame
                 j    0x0(r6)           # return
.pos 0x1000
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
                 .long 0x00000000         
.pos 0x8000
# These are here so you can see (some of) the stack contents.
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
sb: .long 0
