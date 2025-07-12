class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();         // number of rows
        int m = mat[0].size();      // number of columns

        // dp[i][j] will store the maximum gold collected when reaching cell (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the last column with the same values as in mat since it's the end
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = mat[i][m - 1];
        }

        // Traverse the matrix from second-last column to the first
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int right = dp[i][j + 1];
                int right_up = (i - 1 >= 0) ? dp[i - 1][j + 1] : 0;
                int right_down = (i + 1 < n) ? dp[i + 1][j + 1] : 0;

                dp[i][j] = mat[i][j] + max({right, right_up, right_down});
            }
        }

        // Find the max value in the first column
        int maxGold = 0;
        for (int i = 0; i < n; i++) {
            maxGold = max(maxGold, dp[i][0]);
        }

        return maxGold;
    }
};
