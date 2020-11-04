## Code - TODO: Comment and translated to C in q1()
.pos 0x1000

## C statement 1
S1:
ld    $i, r0            #r0 = addr i
ld    (r0), r0          #r0 = i
ld    $a, r1            #r1 = addr a
ld    (r1), r1          #r1 = a* = addr d0
ld    (r1), r1          #r1 = addr d1
ld    (r1, r0, 4), r2   #r2 = d1[0]
ld    $v0, r3           #r3 = addr v0
st    r2, (r3)          #v0 = d1[0]

## C statement 2
S2:
ld    $i, r0            #r0 = addr i
ld    (r0), r0          #r0 = i
ld    $a, r1            #r1 = addr a
ld    (r1), r1          #r1 = a*
inca  r1                #r1 = a* + 4 = addr d0[1]
ld    (r1, r0, 4), r2   #r2 = d0[1]
ld    $v1, r3           #r3 = addr v1
st    r2, (r3)          #v1 = d0[1]

## C statement 3
S3:
ld    $i, r0            #r0 = addr i
ld    (r0), r0          #r0 = i
ld    $a, r1            #r1 = addr a
ld    (r1), r1          #r1 = a*
ld    20(r1), r1        #r1 = d0[5]
ld    (r1), r1          #r1 = addr d3
ld    (r1, r0, 4), r2   #r2 = d3
ld    $v2, r3           #r3 = addr v2
st    r2, (r3)          #v2 = d3

## C statement 4
S4:
ld    $a, r1            #r1 = addr a
ld    (r1), r1          #r1 = a*
st    r1, 20(r1)        #d0[5] = addr d0

## C statement 5
S5:
ld    $i, r0            #r0 = addr i
ld    (r0), r0          #r0 = i
ld    $a, r1            #r1 = addr a
ld    (r1), r1          #r1 = a*
ld    20(r1), r1        #r1 = d0[5] = addr d0
inca  r1                #r1 = addr d0 + 4
ld    (r1, r0, 4), r2   #r2 = d0[1]
ld    $v3, r3           #r3 = addr v3
st    r2, (r3)          #v3 = d0[1]


halt


## Globals
.pos 0x2000
i:  .long 0
v0: .long 0
v1: .long 0
v2: .long 0
v3: .long 0
a:  .long d0


## Heap (these labels represent dynamic values and are thus not available to code)
.pos 0x3000
d0: .long d1
    .long 20
    .long 21
    .long 22
    .long 23
    .long d2
d2: .long d3
    .long 40
    .long 41
    .long 42
    .long 43
    .long 0
d1: .long 10
    .long 11
    .long 12
    .long 13
d3: .long 30
    .long 31
    .long 32
    .long 33
