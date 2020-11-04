.pos 0x100
                 ld   $i, r0              # r0 = &i
                 ld   $a, r1              # r1 = &a[0]
                 ld   $0x0, r2            # r2 = temp_s = 0
                 ld   $0xfffffffb, r4     # r4 = -5
                 ld   $0x0, r6            # r6 = 0
                 st   r6, 0x0(r0)         # r0 = i = 0
                 ld   0x0(r0), r0         # r0 = i
loop:            mov  r0, r5              # r5 = temp_i
                 add  r4, r5              # r5 = temp_i - 5
                 beq  r5, end_loop        # if temp_i = 0, goto +5
                 ld   (r1, r0, 4), r3     # r3 = a[i]
                 inc  r0                  # temp_i++
                 bgt  r3, then            # if a[i] > 0, goto +1
else:            br   loop                
then:            add  r3, r2              # r3 = s_temp + a[i]
                 br   loop                
end_loop:        ld   $s, r1              # r1 = &s
                 st   r2, 0x0(r1)         # s = s_temp
                 st   r0, 0x4(r1)         # i = temp_i
                 halt                     
.pos 0x1000
s:               .long 0x0                # s
i:               .long 0x0                # i
a:               .long 0xa                # a[0]
                 .long 0xffffffe2         # a[1]
                 .long 0xfffffff4         # a[2]
                 .long 0x4                # a[3]
                 .long 0x8                # a[4]
