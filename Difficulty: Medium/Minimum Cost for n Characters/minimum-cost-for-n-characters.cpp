class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        if (n <= 0) return 0;

        // dp[x] stores the minimum cost to reach length x
        vector<long long> dp(n + 1, 0);

        dp[1] = i; // Initial single character insertion

        for (int x = 2; x <= n; ++x) {
            if (x % 2 == 0) {
                // For even numbers: min of (inserting 1 char) or (doubling x/2)
                dp[x] = min(dp[x - 1] + i, dp[x / 2] + c);
            } else {
                // For odd numbers: min of (inserting 1 char) or (doubling (x+1)/2 and deleting 1)
                dp[x] = min(dp[x - 1] + i, dp[(x + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};