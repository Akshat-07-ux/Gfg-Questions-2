#include <vector>

class Solution {
  public:
    int countStrings(int n, int k) {
        // If k is greater than the maximum possible adjacent pairs in length n
        if (k >= n) return 0;
        
        const int MOD = 1e9 + 7;
        
        // dp[j][last] represents the number of strings of the current length
        // with 'j' adjacent 1s ending in 'last' (0 or 1).
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(2, 0));
        
        // Base cases for length 1
        dp[0][0] = 1; // String "0"
        dp[0][1] = 1; // String "1"
        
        // Iterate for lengths from 2 to n
        for (int i = 2; i <= n; ++i) {
            std::vector<std::vector<int>> next_dp(k + 1, std::vector<int>(2, 0));
            
            for (int j = 0; j <= k; ++j) {
                // If we append '0' to the current string
                next_dp[j][0] = (dp[j][0] + dp[j][1]) % MOD;
                
                // If we append '1' to the current string
                next_dp[j][1] = dp[j][0]; // Appending to '0' adds 0 pairs
                if (j > 0) {
                    next_dp[j][1] = (next_dp[j][1] + dp[j - 1][1]) % MOD; // Appending to '1' adds 1 pair
                }
            }
            dp = std::move(next_dp);
        }
        
        // Total valid strings of length n with exactly k pairs
        return (dp[k][0] + dp[k][1]) % MOD;
    }
};