#include <string>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

class Solution {
private:
    int dp[101][901];

    int solve(int idx, int prev_sum, const string &s) {
        // Base case: If we reach the end of the string, we found 1 valid grouping
        if (idx == s.length()) {
            return 1;
        }

        // Return cached result if already calculated
        if (dp[idx][prev_sum] != -1) {
            return dp[idx][prev_sum];
        }

        int current_sum = 0;
        int total_valid_groups = 0;

        // Try forming all possible sub-groups starting from 'idx'
        for (int i = idx; i < s.length(); ++i) {
            current_sum += (s[i] - '0');

            // The sequence must be non-decreasing
            if (current_sum >= prev_sum) {
                total_valid_groups += solve(i + 1, current_sum, s);
            }
        }

        return dp[idx][prev_sum] = total_valid_groups;
    }

public:
    int validGroups(string &s) {
        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));
        
        // Start recursion from index 0 with an initial previous sum of 0
        return solve(0, 0, s);
    }
};