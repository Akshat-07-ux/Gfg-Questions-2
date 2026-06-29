#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        // dp[i][j] stores the max dot product using first i elements of a and first j elements of b
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            // j cannot exceed i because we need at least j elements in 'a' to match with 'b'
            for (int j = 1; j <= min(i, m); j++) {
                
                // Choice 1: Skip the current element of array 'a' (multiply by 0)
                int skip_a = dp[i - 1][j];
                
                // Choice 2: Match a[i-1] with b[j-1]
                int match = dp[i - 1][j - 1] + (a[i - 1] * b[j - 1]);
                
                // We want the maximum of both choices
                dp[i][j] = max(skip_a, match);
            }
        }
        
        return dp[n][m];
    }
};