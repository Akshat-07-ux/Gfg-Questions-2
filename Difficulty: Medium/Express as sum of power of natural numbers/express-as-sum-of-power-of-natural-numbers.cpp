class Solution {
  public:
    int numOfWays(int n, int x) {
        const int MOD = 1e9 + 7;

        vector<int> powers;
        for (int i = 1; ; i++) {
            long long val = pow(i, x);
            if (val > n) break;
            powers.push_back((int)val);
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : powers) {
            for (int sum = n; sum >= p; sum--) {
                dp[sum] = (dp[sum] + dp[sum - p]) % MOD;
            }
        }

        return dp[n];
    }
};
