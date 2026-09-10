class Solution:

    def pairCount(self, x: int, y: int) -> int:
        if y % x != 0:
            return 0
            
        k = y // x
        factors = 0
        d = 2
        
        while d * d <= k:
            if k % d == 0:
                factors += 1
                while k % d == 0:
                    k //= d
                    
            d += 1
            
        if k > 1:
            factors += 1
        
        return 1 << factors
        
