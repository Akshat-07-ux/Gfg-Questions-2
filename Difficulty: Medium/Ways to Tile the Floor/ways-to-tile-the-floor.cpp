class Solution {
  public:
    int countWays(int n, int m) {
        // Base case: If the floor height is less than the tile length m, 
        // we can only place tiles horizontally (1 way).
        if (n < m) {
            return 1;
        }
        
        const int MOD = 1e9 + 7;
        
        // dp[i] stores the number of ways to tile an i x m floor
        vector<int> dp(n + 1, 0);
        
        // Fill base cases for heights from 1 to m-1
        for (int i = 1; i < m; i++) {
            dp[i] = 1;
        }
        
        // If height equals m, we have 2 ways (all horizontal or all vertical)
        dp[m] = 2;
        
        // Build the DP table for heights from m+1 to n
        for (int i = m + 1; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
        }
        
        return dp[n];
    }
};