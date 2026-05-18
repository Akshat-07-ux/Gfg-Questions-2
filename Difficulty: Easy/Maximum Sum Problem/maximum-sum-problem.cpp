class Solution {
  public:
    int maxSum(int n) {
        // Handle base case
        if (n == 0) return 0;
        
        // Create a DP array to store the maximum sum for each value up to n
        vector<int> dp(n + 1, 0);
        
        // Base cases initialized automatically because dp[0] = 0
        for (int i = 1; i <= n; i++) {
            // Choice 1: Do not break the number
            int noBreak = i;
            
            // Choice 2: Break the number into three parts and take their optimal sums
            int breakDown = dp[i / 2] + dp[i / 3] + dp[i / 4];
            
            // Store the maximum of both choices
            dp[i] = max(noBreak, breakDown);
        }
        
        return dp[n];
    }
};