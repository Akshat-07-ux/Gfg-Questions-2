"""
Structure of binary tree Node
class Node:
    def __init__(self, x: int):
        self.data = x
        self.left = self.right = None
"""

from collections import deque
class Solution:

    def areAnagrams(self, root1, root2):
        """ code here """
        if not root1 and not root2:
            return True
            
        if not root1 or not root2:
            return False
            
        d1 = deque([root1])
        d2 = deque([root2])
        
        while d1 and d2:
            s1 = len(d1)
            s2 = len(d2)
            
            if s1 != s2:
                return False
                
            l1 = []
            l2 = []
            
            for _ in range(s1):
                n1 = d1.popleft()
                l1.append(n1.data)
                
                if n1.left:
                    d1.append(n1.left)
                if n1.right:
                    d1.append(n1.right)
                    
            for _ in range(s2):
                n2 = d2.popleft()
                l2.append(n2.data)
                
                if n2.left:
                    d2.append(n2.left)
                if n2.right:
                    d2.append(n2.right)
                    
            if sorted(l1) != sorted(l2):
                return False
                
        return not d1 and not d2
        