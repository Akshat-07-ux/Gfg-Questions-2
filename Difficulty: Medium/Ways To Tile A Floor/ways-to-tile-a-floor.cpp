class Solution {
  public:
    int numberOfWays(int n) {
        // Base cases
        if (n <= 2) return n;

        // dp[i] represents the number of ways to tile a 2 x i board
        int dp1 = 1; // ways for n = 1
        int dp2 = 2; // ways for n = 2
        int dp = 0;

        // Build up the result for n using bottom-up approach
        for (int i = 3; i <= n; i++) {
            dp = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp;
        }

        return dp;
    }
};
