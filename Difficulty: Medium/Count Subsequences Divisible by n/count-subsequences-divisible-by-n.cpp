#include <vector>
#include <string>

class Solution {
  public:
    int countSubsequences(std::string& s, int n) {
        const int MOD = 1e9 + 7;

        // dp[r] stores the count of subsequences with remainder r modulo n
        std::vector<int> dp(n, 0);

        for (char c : s) {
            int digit = c - '0';
            std::vector<int> next_dp = dp;

            // 1. Append current digit to all existing subsequences
            for (int rem = 0; rem < n; ++rem) {
                if (dp[rem] > 0) {
                    int new_rem = (rem * 10 + digit) % n;
                    next_dp[new_rem] = (next_dp[new_rem] + dp[rem]) % MOD;
                }
            }

            // 2. Start a new subsequence consisting solely of the current digit
            int single_rem = digit % n;
            next_dp[single_rem] = (next_dp[single_rem] + 1) % MOD;

            dp = std::move(next_dp);
        }

        return dp[0];
    }
};