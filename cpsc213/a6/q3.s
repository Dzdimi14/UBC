.pos0x1000
    ld $n, r5                   #r5 = address n
    ld (r5), r5                 #r5 = n
#    ld $basedlize, r2           #r2 = addr basedlize
    ld $s, r2
    ld (r2), r2

singavg:                        #compute avg for one student
    ld $4, r0                   #r0 = 4 (i)
    ld $1, r1                   #r1 = 4 (offset)
    ld $0, r3                   #r3 = 0 (sum)
l0: beq r0, end                 #jump to end if there are still grades left
    ld (r2, r1, 4), r4          #r4 = val grade i
    add r4, r3                  #r3 = r4 + sum
    dec r0                      #r0 = r0 - 1
    inc r1                     #r1 = r1 + 4 (next grade offset)
    j l0                        #go back to top of loop
end:
    shr $2, r3
    st r3, (r2, r1, 4)          #st median for student
    dec r5
    ld $24, r6
    add r6, r2
    beq r5, start                 #if no more avg to compute jump to start sort
    j singavg
    halt



    swap:

        ld $0, r6                   #temp 1
        ld $0, r5                   #temp 2
        ld $6, r4                   #r0 = num of elements per student
    l1: beq r4, cnt                 #jump to med once swapped all elements
        dec r4
        ld (r7, r4, 4), r6          #ld s1[r0] into temp 1
        ld $6, r3                   #24 offset between each student
        add r4, r3                  #calculate offset for s2[r0]
        ld (r7, r3, 4), r5         #ld s2[r0] into temp 2
        st r5, (r7, r4, 4)          #st temp 2 into s1[r0]
        st r6, (r7, r3, 4)          #st temp 1 into s2[r0]
        j l1




med:
    dec r0                      #r0 = n-1
    ld $0, r1                   #r1 = temp i = 0
    mov r0, r2
    not r2
    inc r2                      #r2 - -n


l2: beq r2, ct                 #if r2 = 0 go to end
#    ld $basedlize, r3           #r3 = basedlize
    ld $s, r3
    ld (r3), r3
    mov r1, r5                  #r5 = temp i
    mov r1, r4
    mov r1, r6                  #r4 = temp i
    shl $4, r4
    shl $3, r6
    add r6, r4                  #r4 = offset i * 24

    add r3, r4                  #r4 = basedlize + offset
    mov r4, r7                  #r7 = student 1 addr
    ld 20(r4), r4               #r4 = student avg 1

    inc r5
    mov r5, r6
    shl $4, r5
    shl $3, r6
    add r5, r6
    add r3, r6
    ld 20(r6), r6              #r6 = student avg 2


    not r6
    inc r6

    add r6, r4                 #r4 = student 1 - student 2 avg

    bgt r4, swap               #if student 1 > student 2 avg swap
cnt:

    inc r1                     #i++
    inc r2                     #r2++
    j l2





start: ld $n, r0
       ld (r0), r0               #r0 = n

lpt:

    bgt r0, med
    j kill
ct:
    j lpt

kill:
#    ld $basedlize, r1
    ld $s, r1
    ld (r1), r1
    ld $n, r0
    ld (r0), r0
    shr $1, r0

    mov r0, r2
    shl $4, r2
    shl $3, r0
    add r2, r0
    add r1, r0
    ld 20(r0), r0              #r0 = median grade

    ld $m, r3
    st r0, (r3)


 halt




.pos0x2000
n:  .long 9          #dos studientes en este puta
m:  .long 0x0        #median
s:  .long basedlize  #is a dime

.pos0x3000
basedlize:
    .long 1001  #basedlizes student id
    .long 100   #grade 0
    .long 50    #grade 1 (econ probably)
    .long 90    #grade 2
    .long 80    #grade 3
    .long 20    #grade average (compute
    .long 2002  #basedlize2
    .long 12    #basedlize2 is stupid (grade 0)
    .long 5     #grade 1
    .long 20    #grade 2
    .long 100   #grade 3 (this one is in stupid class)
    .long 10    #grade average (compute)
    .long 3003  #basedlize3
    .long 43    #grade 0
    .long 67    #grade 1
    .long 32    #grade 2
    .long 99    #grade 3 (this one is in stupid class)
    .long 100     #grade average (compute)
    .long 6006  #basedlizes student id
    .long 21   #grade 0
    .long 50    #grade 1 (econ probably)
    .long 45    #grade 2
    .long 80    #grade 3
    .long 60    #grade average (compute)
    .long 7007  #basedlizes student id
    .long 38   #grade 0
    .long 70    #grade 1 (econ probably)
    .long 45    #grade 2
    .long 84    #grade 3
    .long 40    #grade average (compute)
    .long 8008  #basedlizes student id
    .long 19  #grade 0
    .long 45    #grade 1 (econ probably)
    .long 93    #grade 2
    .long 84   #grade 3
    .long 20    #grade average (compute)
    .long 9009  #basedlizes student id
    .long 54    #grade 0
    .long 67    #grade 1 (econ probably)
    .long 23    #grade 2
    .long 77    #grade 3
    .long 10    #grade average (compute)
    .long 4004  #basedlizes student id
    .long 100   #grade 0
    .long 50    #grade 1 (econ probably)
    .long 12    #grade 2
    .long 30    #grade 3
    .long 90    #grade average (compute)
    .long 5005  #basedlizes student id
    .long 100   #grade 0
    .long 55    #grade 1 (econ probably)
    .long 64    #grade 2
    .long 80    #grade 3
    .long 60    #grade average (compute)
