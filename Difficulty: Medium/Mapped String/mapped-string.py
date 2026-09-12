class Solution:
    def mapStr(self, n):
        # code here 
        mod = 10**9 + 7
        win = 1
        for i in range(1, n + 1):
            win = (win * i) % mod
            
        return win