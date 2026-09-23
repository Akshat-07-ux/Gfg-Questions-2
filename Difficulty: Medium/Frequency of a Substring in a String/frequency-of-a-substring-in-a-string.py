class Solution:

    def countFreq(self, s1, s2):
        """ code here """
        
        n, m = len(s1), len(s2)
        if m > n:
            return 0
            
        return sum(1 for i in range(n - m + 1) if s1[i:i+m] == s2)
