class Solution {
  public:
    int optimalKeys(int n) {
        // If n is small, the best result is just pressing 'A' n times.
        if (n <= 6) {
            return n;
        }

        // dp[i] will store the maximum number of 'A's using i keystrokes.
        // Using long long to prevent potential overflow for larger constraints.
        long long dp[n + 1];

        // Base cases for n <= 6
        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }

        for (int i = 7; i <= n; i++) {
            dp[i] = 0;
            
            // To get the max 'A's for i keystrokes, we look back at 
            // previous states j and see if copying dp[j] yields a better result.
            // We need at least 3 keys to Select, Copy, and Paste (i-3).
            for (int j = i - 3; j >= 1; j--) {
                // The multiplier is (i - j - 1).
                // Example: if i=7 and j=4, multiplier is (7-4-1) = 2.
                // Keys: [4 keys to get dp[4]], Ctrl-A (5), Ctrl-C (6), Ctrl-V (7).
                long long current = dp[j] * (i - j - 1);
                if (current > dp[i]) {
                    dp[i] = current;
                }
            }
        }

        return (int)dp[n];
    }
};