#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        // Initialize tracking variables with the first element
        int max_no_skip = arr[0];
        int max_one_skip = arr[0];
        int overall_max = arr[0];

        for (int i = 1; i < n; i++) {
            // max_one_skip for current position depends on previous states
            // 1. Skip the current element: max_no_skip (from i-1)
            // 2. Keep the current element but use a previous skip: max_one_skip + arr[i]
            max_one_skip = max(max_no_skip, max_one_skip + arr[i]);

            // Standard Kadane's algorithm for no skips
            max_no_skip = max(arr[i], max_no_skip + arr[i]);

            // Update the global maximum encountered so far
            overall_max = max({overall_max, max_no_skip, max_one_skip});
        }

        return overall_max;
    }
};