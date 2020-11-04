.pos 0x1000
code:
        ld $v0, r0              #r0 = & v0
        ld $i , r1              #r1 = & i
        ld $s , r2              #r2 = & s = &x[0]
        ld (r1), r1             #r1 = val i
        ld (r2, r1, 4), r3      #r3 = s.x[i]
        st r3, (r0)             #v0 = s.x[i]

        ld $v1, r0              #r0 = & v1
        ld 0x8(r2), r3          #r3 = & s.y
        ld (r3, r1, 4), r3      #r3 = s.y[i]
        st r3, (r0)             #v1 = s.y[i]

        ld $v2, r0              #r0 = & v2
        ld 0xc(r2), r3          #r3 = & s.z
        ld (r3, r1, 4), r3      #r3 = s.z->x[i]
        st r3, (r0)             #r0 = s.z->x[i]

        ld $v3, r0              #r0 = & v3
        ld 0xc(r2), r3          #r3 = & s.z
        ld 0xc(r3), r3          #r3 = &s.z->z
        ld 0x8(r3), r3          #r3 = &s.z->z->y
        ld (r3, r1, 4), r3      #r3 = s.z->z->y[i]
        st r3, (r0)
      halt
.pos0x2000
static:
i:     .long 0x1                  #int i
v0:    .long 0                  #int v0
v1:    .long 0
v2:    .long 0
v3:    .long 0
s:     .long 0x3                #struct s x[0]
       .long 0x4                #x[1]
       .long s_y                #int* y y is pointer to int
       .long s_z                #S* z is pointer to struct s

.pos0x3000
heap:
s_y:   .long 0x1                #s.y[0]
        .long 0x2               #s.y[1]
s_z:   .long 0x5                #s.z->x[0]
       .long 0x6                 #s.z->x[1]
       .long 0                  #s.z->y
       .long s_z_z              #s.z->z
s_z_z: .long 0                  #s.z->z->x[0]
       .long 0                  #s.z->z->x[1]
       .long s_z_z_y            #s.z->z->y
s_z_z_y:
       .long 0x7                  #s.z->z->y[0]
       .long 0x8                  #s.z->z->y[1]
