class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // If sum is 0, no coins are needed
        if (sum == 0) return 0;

        // Create a dp array of size sum + 1
        // We initialize with sum + 1 because the maximum number of coins 
        // possible would be 'sum' (if using coins of denomination 1).
        vector<int> dp(sum + 1, sum + 1);

        // Base case: 0 coins needed for sum 0
        dp[0] = 0;

        // Iterate through all sums from 1 to sum
        for (int i = 1; i <= sum; i++) {
            // Try every coin
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[sum] is still sum + 1, it means the sum is unreachable
        return (dp[sum] > sum) ? -1 : dp[sum];
    }
};