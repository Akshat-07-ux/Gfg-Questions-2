''' Binary Tree Node Structure
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''
from collections import deque
class Solution:
    def getCount(self, root, k):
        # code here
        if not root:
            return 0
            
        leaf_price = []
        queue = deque([(root, 1)])
        
        while queue:
            node, level = queue.popleft()
            
            if not node.left and not node.right:
                leaf_price.append(level)
                
            if node.left:
                queue.append((node.left, level + 1))
                
            if node.right:
                queue.append((node.right, level + 1))
                
        leaf_price.sort()
        total_price = 0
        count = 0
        
        for price in leaf_price:
            if total_price + price <= k:
                total_price += price
                count += 1
                
            else:
                break
            
        return count
                
        