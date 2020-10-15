import math

dom = [1,2,3,4]

print("\nSolutions: \nA B C D E F G H")
expanded = 0
fail = 0
for A in dom:
    expanded += 1
    for B in dom:
        expanded += 1
        for C in dom:
            expanded += 1
            for D in dom:
                expanded += 1
                if D != C:
                    for E in dom:
                        expanded += 1
                        if E != C and E < D - 1:
                            for F in dom:
                                expanded += 1
                                if C != F and D != F and (abs(E - F) % 2 != 0) and abs(F - B) == 1:
                                    for G in dom:
                                        expanded += 1
                                        if A > G and abs(G-C) == 1 and D > G:
                                            for H in dom:
                                                expanded +=1
                                                if (H - C)%2==0 and H != D and E != H -2 and H !=F:
                                                    print(A, B, C, D, E, F, G, H)
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





