from collections import Counter
class Solution:
    def minRemove(self, a, b):
        # code here.
        c_a = Counter(a)
        c_b = Counter(b)
        
        remove = 0
        for cnt in c_a:
            if cnt in c_b:
                remove += min(c_a[cnt], c_b[cnt])
                
        return remove
