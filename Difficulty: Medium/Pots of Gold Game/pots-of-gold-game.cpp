class Solution {
  public:
    int maxCoins(vector<int>& A, int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one pot
        for (int i = 0; i < n; i++) {
            dp[i][i] = A[i];
        }

        // Fill DP table for increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                int pickLeft = A[i] + min(
                    (i + 2 <= j) ? dp[i + 2][j] : 0,
                    (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0
                );

                int pickRight = A[j] + min(
                    (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0,
                    (i <= j - 2) ? dp[i][j - 2] : 0
                );

                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        return dp[0][n - 1];
    }
};
