#!/usr/bin/env python
# coding: utf-8

# In[55]:



dom = [1,2,3,4]


print("\nSolutions:\nA B C D E F G H")


                        
fail = 0
expanded = 1


for A in dom:
    expanded += 1
    for B in dom:
        expanded += 1
        for C in dom:
            expanded += 1
            for D in dom:
                if D != C:
                    expanded += 1
                    for E in dom:
                        if E !=C and E < (D - 1):
                            expanded += 1
                            for F in dom:
                                if C != F and D != F and abs(E - F) % 2 != 0 and abs(F - B) == 1:
                                    expanded += 1
                                    for G in dom:
                                        if A > G and abs(G - C) == 1 and D > G and G != F:
                                            expanded += 1
                                            for H in dom:
                                                if A <= H and G < H and (H - C) % 2 == 0 and H != D and E != (H - 2) and H != F:
                                                    expanded += 1
                                                    print(A,B,C,D,E,F,G,H)
                                                else:
                                                    fail += 1
                                        else:
                                            fail+=1
                                else:
                                    fail+= 1
                        else: 
                            fail+=1
                else:
                    fail+=1

                
print("Search: number of failures:",fail)
print("Number of nodes expanded:",expanded)

