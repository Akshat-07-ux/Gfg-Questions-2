class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);

        // Each element itself is a subsequence
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }

        // Compute Maximum Sum Increasing Subsequence
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        // Answer is the maximum value in dp[]
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
