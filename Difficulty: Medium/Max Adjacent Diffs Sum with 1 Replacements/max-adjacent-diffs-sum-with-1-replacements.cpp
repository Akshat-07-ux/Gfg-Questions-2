#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // dp1: max sum ending at index i where arr[i] is replaced with 1
        // dp2: max sum ending at index i where arr[i] remains original value
        int dp1 = 0;
        int dp2 = 0;

        for (int i = 1; i < n; i++) {
            int next_dp1 = max(dp1 + abs(1 - 1), 
                               dp2 + abs(1 - arr[i - 1]));

            int next_dp2 = max(dp1 + abs(arr[i] - 1), 
                               dp2 + abs(arr[i] - arr[i - 1]));

            dp1 = next_dp1;
            dp2 = next_dp2;
        }

        return max(dp1, dp2);
    }
};