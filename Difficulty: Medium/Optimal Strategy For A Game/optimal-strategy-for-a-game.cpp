class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int g = 0; g < n; g++) {   // g = gap
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) {
                    dp[i][j] = arr[i];
                } 
                else if (g == 1) {
                    dp[i][j] = max(arr[i], arr[j]);
                } 
                else {
                    long long x = dp[i+2][j];     // if pick i, opponent picks i+1
                    long long y = dp[i+1][j-1];   // if either picks the inner
                    long long z = dp[i][j-2];     // if pick j, opponent picks j-1

                    long long pickLeft  = arr[i] + min(x, y);
                    long long pickRight = arr[j] + min(y, z);

                    dp[i][j] = max(pickLeft, pickRight);
                }
            }
        }

        return dp[0][n-1];
    }
};
