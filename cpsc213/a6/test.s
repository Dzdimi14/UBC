.pos 0x1000

beq: ld $0, r0      #r0 = 0
     ld $1, r1      #r1 = 1
     beq r1, fail   #if says r1 is 0 fail
     beq r0, bgt    #if says r0 is 0 pass

bgt: bgt r0, fail
     bgt r1, jmp
     halt

jmp: j pc
     halt

pc: gpc $4, r2
    j 2(r2)
    halt


    nop
    halt
fail:
    halt
