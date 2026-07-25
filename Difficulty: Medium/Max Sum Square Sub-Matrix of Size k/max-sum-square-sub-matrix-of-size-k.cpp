class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        // Prefix sum array
        vector<vector<long long>> prefix(n + 1, vector<long long>(n + 1, 0));

        // Build prefix sums
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        long long ans = LLONG_MIN;

        // Check every k x k sub-grid
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                long long sum = prefix[i][j]
                              - prefix[i - k][j]
                              - prefix[i][j - k]
                              + prefix[i - k][j - k];

                ans = max(ans, sum);
            }
        }

        return (int)ans;
    }
};