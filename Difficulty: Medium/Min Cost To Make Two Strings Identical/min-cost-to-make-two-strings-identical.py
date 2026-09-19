class Solution:
    def findMinCost(self, s1: str, s2: str, costS1: int, costS2: int) -> int:
        # code here
        k, l = len(s1), len(s2)
        
        dp = [[0] * (l + 1) for _ in range(k + 1)]
        
        for i in range(1, k + 1):
            for j in range(1, l + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                    
        lcs_l = dp[k][l]
        
        return (k - lcs_l) * costS1 + (l - lcs_l) * costS2