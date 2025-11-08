class Solution {
  public:
    int chocolatePickup(vector<vector<int>> &mat) {
        int n = mat.size();
        if (mat[0][0] == -1 || mat[n-1][n-1] == -1) return 0;

        // dp[i1][j1][i2] = max chocolates when
        // person1 is at (i1, j1) and person2 is at (i2, j2)
        // where j2 = i1 + j1 - i2
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][0] = mat[0][0];

        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int i2 = 0; i2 < n; i2++) {
                    int j2 = i1 + j1 - i2;
                    if (j2 < 0 || j2 >= n) continue;
                    if (mat[i1][j1] == -1 || mat[i2][j2] == -1) continue;
                    if (i1 == 0 && j1 == 0 && i2 == 0) continue;

                    int bestPrev = INT_MIN;

                    // Four possible previous moves
                    if (i1 > 0 && i2 > 0)
                        bestPrev = max(bestPrev, dp[i1-1][j1][i2-1]);
                    if (i1 > 0 && j2 > 0)
                        bestPrev = max(bestPrev, dp[i1-1][j1][i2]);
                    if (j1 > 0 && i2 > 0)
                        bestPrev = max(bestPrev, dp[i1][j1-1][i2-1]);
                    if (j1 > 0 && j2 > 0)
                        bestPrev = max(bestPrev, dp[i1][j1-1][i2]);

                    if (bestPrev == INT_MIN) continue;

                    int val = mat[i1][j1];
                    if (i1 != i2 || j1 != j2)
                        val += mat[i2][j2];

                    dp[i1][j1][i2] = bestPrev + val;
                }
            }
        }

        return max(0, dp[n-1][n-1][n-1]);
    }
};
