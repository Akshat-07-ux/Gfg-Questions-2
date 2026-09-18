'''
Binary Tree Node Structure
class Node:
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None
'''
        
class Solution:
    def absDiff(self, root):
        # code here
        self.less = float('inf')
        self.last = None
        
        def in_the_order(node):
            if not node:
                return 
                
            in_the_order(node.left)
                
            if self.last is not None:
                self.less = min(self.less, node.data - self.last)
            self.last = node.data
                    
            in_the_order(node.right)
                
        in_the_order(root)
        return self.less