# CPSC 322 Assignment 3 code
# Copyright David Poole 2020.
# Released under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.

# Search for finding a solution to CSP X !=Y and Y != Z
dom = ["t","f"]


print("\nSolutions:\nX Y Z")

for X in dom:
    for Y in dom:
        if X != Y:
            for Z in dom:
                if Y != Z:
                    print(X,Y,Z)

print("\nWith counting:")
fails = 0
expanded = 1 # for root node

for X in dom:
    expanded += 1
    for Y in dom:
        if X != Y:
            expanded += 1
            for Z in dom:
                if Y != Z:
                    expanded += 1
                    print(X,Y,Z)
                else:
                    fails +=1
        else:
            fails += 1
                
print("Search: number of failures:",fails)
print("Number of nodes expanded:",expanded)

# Or using generate and test:

print("\nGenerate and Test (goal is satisfying constraints)")

# Without statistics
for X in dom:
    for Y in dom:
        for Z in dom:
            if X !=Y and Y != Z:
                print(X,Y,Z)

print("\nWith counting:")

                
gtfails = 0
gtexpanded = 1
for X in dom:
    gtexpanded += 1
    for Y in dom:
        gtexpanded += 1
        for Z in dom:
            gtexpanded += 1
            if X !=Y and Y != Z:
                print(X,Y,Z)
            else:
                gtfails +=1

print("Generate and test: number of failures:",gtfails)
print("Generate and test: number nodes expanded:",gtexpanded)

