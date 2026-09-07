class Solution {
  public:
    int minCount(vector<int>& arr) {
        int n = arr.size();
        // dp[i][j] stores the max elements included where:
        // i is the last element of the increasing subsequence (0 to 100, 0 means empty)
        // j is the last element of the decreasing subsequence (0 to 101, 101 means empty)
        vector<vector<int>> dp(101, vector<int>(102, -1));
        dp[0][101] = 0;

        for (int x : arr) {
            vector<vector<int>> next_dp = dp;
            for (int i = 0; i <= 100; ++i) {
                for (int j = 0; j <= 101; ++j) {
                    if (dp[i][j] != -1) {
                        // Try adding x to the increasing subsequence
                        if (x > i) {
                            next_dp[x][j] = max(next_dp[x][j], dp[i][j] + 1);
                        }
                        // Try adding x to the decreasing subsequence
                        if (x < j) {
                            next_dp[i][x] = max(next_dp[i][x], dp[i][j] + 1);
                        }
                    }
                }
            }
            dp = move(next_dp);
        }

        int max_included = 0;
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 101; ++j) {
                max_included = max(max_included, dp[i][j]);
            }
        }

        return n - max_included;
    }
};