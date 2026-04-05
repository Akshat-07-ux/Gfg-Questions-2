#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }

        // Logical checks:
        // 1. target cannot be greater than the total possible sum.
        // 2. (sum + target) must be even and non-negative to find a valid subset sum.
        if (abs(target) > sum || (sum + target) % 2 != 0 || (sum + target) < 0) {
            return 0;
        }

        int subsetSum = (sum + target) / 2;
        
        // dp[i] stores the number of ways to get sum 'i'
        vector<int> dp(subsetSum + 1, 0);
        
        // Base case: There is 1 way to get a sum of 0 (by choosing an empty subset)
        dp[0] = 1;

        for (int num : arr) {
            // Iterate backwards to ensure we use each element only once 
            // and don't overwrite values needed for the current iteration.
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};