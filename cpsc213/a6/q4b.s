.pos 0x100
start:
    ld $sb, r5			# sp = addr of last word of stack
    inca    r5			# sp = addr of word after stack
    gpc $6, r6			# r6 = pc + 6
    j main				# call main()
    halt

f:
    deca r5				# allocate space on stack (callee part of f's frame)
    ld $0, r0			# r0 = r = 0
    ld 4(r5), r1		# r1 = a0 = x[i]
    ld $0x80000000, r2	# r2 = biggest 32-bit negative number (binary: 1 with lots of 0s)
f_loop:
    beq r1, f_end		# if a0 == 0, goto f_end
    mov r1, r3			# copy r1 to r3 = a
    and r2, r3			# a = 0x80000000 && a
    beq r3, f_if1		# if a = 0, goto f_if1
    inc r0				# r++
f_if1:
    shl $1, r1			# r1 * 2
    br f_loop			# goto f_loop
f_end:
    inca r5				# deallocate space on stack (callee part of f's frame)
    j(r6)

main:
    deca r5				
    deca r5				# allocate space on stack (size of callee part of main's frame)
    st r6, 4(r5)		# save ra of start on stack
    ld $8, r4			# r4 = 8 = i = size of array
main_loop:
    beq r4, main_end	# goto main_end if i == 0
    dec r4				# size of array - 1
    ld $x, r0			# r0 = addr of x[0]
    ld (r0,r4,4), r0	# r0 = a0 = x[i]
    deca r5				# allocate space on stack (caller part of f's frame)
    st r0, (r5)			# save a0 = x[i] on stack
    gpc $6, r6			# r6 = ra of main_loop
    j f					# goto f(a0) = f(x[i])
    inca r5				# deallocate space on stack (caller part of f's frame)
    ld $y, r1			# r1 = addr of y[0]
    st r0, (r1,r4,4)	# y[i] = r
    br main_loop
main_end:
    ld 4(r5), r6		# get ra of start
    inca r5				
    inca r5				# deallocate space on stack (size of callee part of main's frame)
    j (r6)				# return

.pos 0x2000
x:
    .long 1
    .long 2
    .long 3
    .long 0xffffffff
    .long 0xfffffffe
    .long 0
    .long 184
    .long 340057058

y:
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0

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

