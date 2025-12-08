class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> split(n, vector<int>(n, 0));

        // dp[i][j] = minimum cost to multiply matrices i to j
        for (int len = 2; len < n; ++len) { // length of chain
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int cost = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k; // store split point
                    }
                }
            }
        }

        // Function to recursively build the string
        function<string(int,int)> build = [&](int i, int j) -> string {
            if (i + 1 == j) return string(1, 'A' + i); // single matrix
            int k = split[i][j];
            return "(" + build(i, k) + build(k, j) + ")";
        };

        return build(0, n-1);
    }
};
