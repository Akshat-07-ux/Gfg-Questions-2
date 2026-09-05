#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        // Find the maximum value to appropriately size our DP array
        int max_val = 0;
        for (int x : arr) {
            if (x > max_val) {
                max_val = x;
            }
        }

        // dp[x] stores the length of the longest subsequence ending with value x
        // Size is max_val + 2 to safely access x + 1 without out-of-bound errors
        vector<int> dp(max_val + 2, 0);
        int max_len = 0;

        for (int x : arr) {
            int len = 0;

            // Check the length of subsequences ending in x - 1 and x + 1
            if (x > 0) {
                len = max(len, dp[x - 1]);
            }
            len = max(len, dp[x + 1]);

            // Update the DP state for the current element
            dp[x] = len + 1;

            // Track the overall maximum length found so far
            if (dp[x] > max_len) {
                max_len = dp[x];
            }
        }

        return max_len;
    }
};