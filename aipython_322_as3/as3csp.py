o# CPSC 322 Assignment 3 code
# Copyright David Poole 2020.
# Released under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.

from cspProblem import CSP, Constraint        
from operator import lt,ne,eq,gt,le   # standard Python functions

dom = {1,2,3,4}
as3csp = CSP({'A':dom, 'B':dom, 'C':dom, 'D':dom, 'E':dom,
              'F':dom, 'G':dom, 'H':dom},
             [ Constraint(['A','H'], le),
               Constraint(['A','G'], gt),
               Constraint(['B','F'], lambda b,f: abs(b-f)==1),
               Constraint(['G','H'], lt),
               Constraint(['G','C'], lambda g,c: abs(g-c)==1),
               Constraint(['H','C'], lambda h,c: abs(h-c)%2==0),
               Constraint(['H','D'], ne),
               Constraint(['D','G'], gt),
               Constraint(['D','C'], ne),
               Constraint(['E','C'], ne),
               Constraint(['E','D'], lambda e,d:e<d-1),
               Constraint(['E','H'], lambda e,h:e != h-2),
               Constraint(['G','F'], ne),
               Constraint(['H','F'], ne),
               Constraint(['C','F'], ne),
               Constraint(['D','F'], ne),
               Constraint(['E','F'], lambda e,f: abs(e-f)%2==1) ])

#from searchGeneric import Searcher
#from cspSearch import Search_from_CSP
#sn = Searcher(Search_from_CSP(as2csp,['A','B','C','D','E','F','G','H']))
#print(sn.search())  # get next solution

#from cspConsistency import Search_with_AC_from_CSP
#schr = Searcher(Search_with_AC_from_CSP(as2csp))
#print(schr.search())
