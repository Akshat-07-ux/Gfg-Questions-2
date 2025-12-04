class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> ps(n + 1, 0);  // prefix sum of frequencies

        for (int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + freq[i];

        auto rangeSum = [&](int l, int r) {
            return ps[r + 1] - ps[l];
        };

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (i == j) {
                    dp[i][j] = freq[i];
                } else {
                    int best = INT_MAX;
                    int totalFreq = rangeSum(i, j);

                    for (int r = i; r <= j; r++) {
                        int left = (r > i) ? dp[i][r - 1] : 0;
                        int right = (r < j) ? dp[r + 1][j] : 0;
                        best = min(best, left + right);
                    }

                    dp[i][j] = best + totalFreq;
                }
            }
        }

        return dp[0][n - 1];
    }
};
