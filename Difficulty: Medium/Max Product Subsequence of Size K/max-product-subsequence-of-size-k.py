from functools import lru_cache
class Solution:
    def maxProduct(self, arr: list[int], k: int) -> int:
        @lru_cache(None)
        
        def help(i: int, last: int) -> tuple[float, float]:
            if last == 0:
                return (1,1)
                
            if i == len(arr) or len(arr) - i < last:
                return (float('-inf'), float('inf'))
                
            max_exe, min_exe = help(i + 1, last)
            max_sub, min_sub = help(i + 1, last - 1)
            
            if max_sub == float('-inf'):
                return (max_exe, min_exe)
                
            equal = arr[i]
            r1, r2 = equal * max_sub, equal * min_sub
            max_inc, min_inc = max(r1, r2), min(r1, r2)
            
            return (max(max_exe, max_inc), min(min_exe, min_inc))
            
        return int(help(0, k)[0])
