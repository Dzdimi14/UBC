# CPSC 322 2020. Assignment 1 solution code and Assignment 2 starter code.
# Copyright David Poole 2020. Not for redistribution.

from searchProblem import Search_problem, Arc

# a state is a triple ((x,y),c) where
#   robot is at position (x,y) where the bottom left location is (0,0)
#   Boolean c specified whether the robot has coffee
import random
class CoffeeProblem(Search_problem):

    def start_node(self):
        """returns the start node"""
        return ((3,2),False)
    
    def is_goal(self,node):
        """returns True when node is a goal node"""
        return node == ((3,4),True)
    
    def neighbors(self,node):
        """returns a list of the neighbors of node.
           note that the neighbors are arcs.
        """
        ((x,y),c) = node
        return [Arc(node,(pos,True))
                  if self.at_coffee(pos)
                  else Arc(node,(pos,c))
                for pos in ((x+dx, y+dy) for (dx,dy) in [(-1,0),(1,0),(0,1),(0,-1)])
                if self.legal(x,y)]
   
    def legal(self,x,y):
        """returns True when position (x,y) is a legal position"""
        return x>=0 and x<9 and y>=0 and y<6 and (
            y in [0,5] if x==1 else
            (x==0 or x>5 if y==3 else
            (x,y) != (5,4)))
    
    def at_coffee(self,pos):
        """returns True when pos is a locoation of a coffee shop"""
        return pos in [(0,0),(4,0),(7,4)]

 #   def heuristic(self, n):
        #take manhattan distance of start node and goal node
#        goalx = 3
 #       goaly = 4
  #      
   #     return abs(x - goalx) + abs(y - goaly)
    def heuristic(self, n):
        goalx = 3
        goaly = 4

        ((x,y), c) = n
        coffeelocs= [(0,0),(4,0),(7,4)]
        
        min = 100
        selected_x = 0
        selected_y = 0
        #find manhattan distance to nearest coffee
        for (x1,y1) in coffeelocs:
            dist = abs(x - x1) + abs(y - y1)
            if dist < min:
                min = dist
                (selected_x, selected_y) = (x1, y1)

        if c:
            return abs(x - goalx) + abs(y - goaly)
        else:
            return abs(x - selected_x) + abs(y - selected_y)

    
        


        
        

        
from searchGeneric import Searcher, AStarSearcher
from searchMPP import SearcherMPP

# Try some of the following in iPython (or uncomment):
print("\nA* with MPP and h1=0:")
coffeesearchermpp = SearcherMPP(CoffeeProblem())
print(coffeesearchermpp.search())
print("A* without MPP with h1 (warning slow):")
coffeesearchera = AStarSearcher(CoffeeProblem())
print(coffeesearchera.search())
