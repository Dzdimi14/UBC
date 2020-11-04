.pos 0x0                                    #sets up stack?
                 ld   $0x1028, r5           #&stack = r5
                 ld   $0xfffffff4, r0       #r0 = -12
                 add  r0, r5                #r5 = stack - 12
                 ld   $0x200, r0            #r0 = &i
                 ld   0x0(r0), r0           #r0 = i
                 st   r0, 0x0(r5)           #i[0] = r0 = i
                 ld   $0x204, r0            #r0 = &k
                 ld   0x0(r0), r0           #r0 = k
                 st   r0, 0x4(r5)           #i[1] = k
                 ld   $0x208, r0            #r0 = &j
                 ld   0x0(r0), r0           #r0 = j
                 st   r0, 0x8(r5)           #i[2] = j
                 gpc  $6, r6                #r6 = pc + 6
                 j    0x300                 #goto q2.c
                 ld   $0x20c, r1            #r1 = &s {END}
                 st   r0, 0x0(r1)           #s = r0
                 halt
.pos 0x200
                 .long 18               #i
                 .long 54               #k
                 .long 54               #j
                 .long 52               #s
.pos 0x300                                          #q2.c
                 ld   0x0(r5), r0       #i[0] = r0
                 ld   0x4(r5), r1       #i[1] = r1
                 ld   0x8(r5), r2       #i[2] = r2
                 ld   $0xfffffff6, r3   #r3 = -10
                 add  r3, r0            #r0 = i[0] - 10
                 mov  r0, r3            #r3 = i[0] - 10
                 not  r3                #r3 = ~r3
                 inc  r3                #r3 = 10 - i[0]
                 bgt  r3, L6            #i[0] < 10 goto L6
                 mov  r0, r3            #r0 = r3
                 ld   $0xfffffff8, r4   #r4 = -8
                 add  r4, r3            #r3 = r4 + r3
                 bgt  r3, L6            #i[0] > 18 goto L5
                 ld   $0x400, r3        #r3 = &jumptable
                 j    *(r3, r0, 4)      #goto(jumpTable[i - 10]) (if odd(i- 10 go) to default)
.pos 0x330
case1:           add  r1, r2            #case 1 (i[1] = i[1] + i[2])
                 br   L7                #goto L7
case2:           not  r2                #case 2
                 inc  r2
                 add  r1, r2            #(i[2] = i[1] - i[2])
                 br   L7                #goto l7
case3:           not  r2                #~r2
                 inc  r2                #
                 add  r1, r2            #-r2
                 bgt  r2, L0            #if (i[1] > i[2]) goto l0
                 ld   $0x0, r2          #else r2 = 0
                 br   L1                #goto L1
L0:              ld   $0x1, r2          #case 4 r2 = 1
L1:              br   L7                #goto L7
                 not  r1                #~i[1]
                 inc  r1                #-i[1]
                 add  r2, r1            #i[2] - i[1]
                 bgt  r1, L2            #if (i[1] < i[2]) goto L2
                 ld   $0x0, r2          #r2 = 0
                 br   L3                #goto L3
L2:              ld   $0x1, r2          #r2 = 1
L3:              br   L7                #goto L7
                 not  r2                #~i[2]
                 inc  r2                #-i[2]
                 add  r1, r2            #i[1] - i[2]
                 beq  r2, L4            #if (i[1] == i[2]) goto L4
                 ld   $0x0, r2          #r2 = 0
                 br   L5                #goto L5
L4:              ld   $0x1, r2          #r2 = 1
L5:              br   L7                #goto L7
L6:              ld   $0x0, r2          #DEFUALT r2 = 0
                 br   L7                #goto L7
L7:              mov  r2, r0            #r0 = r2
                 j    0x0(r6)           #jump to end
.pos 0x400                              #jumptable
                 .long 0x00000330       #addr case 1  [i-10] = 0
                 .long 0x00000384       #addr default [i-10] = 1
                 .long 0x00000334       #addr case 2  [i-10] = 2
                 .long 0x00000384       #addr defualt [i-10] = 3
                 .long 0x0000033c       #addr case 3  [i-10] = 4
                 .long 0x00000384       #addr default [i-10] = 5
                 .long 0x00000354       #addr case 4  [i-10] = 6
                 .long 0x00000384       #addr defualt [i-10] = 7
                 .long 0x0000036c       #addr case 5  [i-10] = 8
.pos 0x1000                             #STACK
                 .long 20
                 .long 30
                 .long 30
                 .long 40
                 .long 50
                 .long 50
                 .long 50
                 .long 60              #i[0]
                 .long 40              #i[1]
                 .long 40              #i[2]
