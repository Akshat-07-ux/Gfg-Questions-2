class Solution {
  public:
    int count(int n, int m) {
        // dp[i][val] will store the number of valid arrays of length i ending with 'val'
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Base case: For length 1, every element in [1, m] can form 1 array
        for (int val = 1; val <= m; ++val) {
            dp[1][val] = 1;
        }
        
        // Fill DP table for lengths 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int curr = 1; curr <= m; ++curr) {
                for (int prev = 1; prev <= m; ++prev) {
                    // One element must divide the other
                    if (curr % prev == 0 || prev % curr == 0) {
                        dp[len][curr] += dp[len - 1][prev];
                    }
                }
            }
        }
        
        // Sum up the count of all arrays of length n ending with any valid number in [1, m]
        int total = 0;
        for (int val = 1; val <= m; ++val) {
            total += dp[n][val];
        }
        
        return total;
    }
};