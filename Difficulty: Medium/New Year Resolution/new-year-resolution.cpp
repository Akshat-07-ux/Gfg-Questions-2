#include <bitset>

class Solution {
  public:
    int isPossible(int N, int coins[]) {
        // bitset<2025> represents all possible sums from 0 to 2024.
        // dp[s] == 1 means sum 's' is achievable.
        std::bitset<2025> dp;
        
        // Base case: sum 0 is possible
        dp[0] = 1;
        
        for (int i = 0; i < N; i++) {
            // This single line replaces the inner loop.
            // (dp << coins[i]) creates a new bitset where every reachable sum
            // is shifted forward by the value of the current coin.
            // '|' (OR) combines the old reachable sums with the new ones.
            dp |= (dp << coins[i]);
        }
        
        // Check eligibility criteria
        for (int s = 1; s <= 2024; s++) {
            if (dp[s]) {
                if (s % 20 == 0 || s % 24 == 0 || s == 2024) {
                    return 1;
                }
            }
        }
        
        return 0;
    }
};