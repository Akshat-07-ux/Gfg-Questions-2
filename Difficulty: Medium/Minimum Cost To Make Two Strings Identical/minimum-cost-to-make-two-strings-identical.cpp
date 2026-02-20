class Solution {
  public:
    int findMinCost(string x, string y, int costX, int costY) {
        int m = x.length();
        int n = y.length();
        
        // dp[i][j] will store the length of LCS of x[0..i-1] and y[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (x[i - 1] == y[j - 1]) {
                    // Characters match, increment LCS length
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Characters don't match, take the maximum from neighbors
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int lcsLength = dp[m][n];
        
        // Calculate characters to be deleted
        int delX = m - lcsLength;
        int delY = n - lcsLength;
        
        return (delX * costX) + (delY * costY);
    }
};