class Solution:
    def maximumIntegerValue(self, s: str) -> int:
        # code here
        if not s:
            return 0
            
        adj = int(s[0])
        for i in range(1, len(s)):
            a = int(s[i])
            adj = max(adj + a, adj * a)
            
        return adj