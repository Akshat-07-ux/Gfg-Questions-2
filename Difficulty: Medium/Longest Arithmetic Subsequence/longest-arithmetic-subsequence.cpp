class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return n;

        int max_val = arr[n - 1];
        int min_val = arr[0];
        int max_diff = max_val - min_val;

        // dp[i][d] stores the length of AP ending at index i with difference d
        // We use n x (max_diff + 1) to cover all possible differences
        vector<vector<int>> dp(n, vector<int>(max_diff + 1, 1));
        int ans = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];
                
                // If we found an AP ending at j with 'diff', extend it
                // Otherwise, the length is 2 (the pair arr[j] and arr[i])
                dp[i][diff] = dp[j][diff] + 1;
                
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};