class Solution:
    def maxLenSub(self, arr):
        # Code Here
        dp = {}
        
        comp_len = 0
        
        for a in arr:
            len = 1 + max(
                dp.get(a - 1, 0),
                dp.get(a, 0),
                dp.get(a + 1, 0)
            )
            dp[a] = len
            if len > comp_len:
                comp_len = len
                
        return comp_len