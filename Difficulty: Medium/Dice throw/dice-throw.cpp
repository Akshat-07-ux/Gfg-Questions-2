class Solution {
  public:
    long long noOfWays(int m, int n, int x) {
        // dp[i][j] = number of ways to get sum j using i dice
        // Using long long to handle large numbers, though x <= 50 is small
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));

        // Base case: 0 dice can form a sum of 0 in exactly 1 way
        dp[0][0] = 1;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {           // For each die
            for (int j = 1; j <= x; j++) {       // For each possible total sum
                for (int k = 1; k <= m; k++) {   // For each face of the current die
                    if (j - k >= 0) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }

        return dp[n][x];
    }
};