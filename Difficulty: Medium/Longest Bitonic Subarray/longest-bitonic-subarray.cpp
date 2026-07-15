#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // inc[i] stores the length of the longest increasing subarray ending at arr[i]
        vector<int> inc(n, 1);
        // dec[i] stores the length of the longest decreasing subarray starting at arr[i]
        vector<int> dec(n, 1);

        // Step 1: Populate the inc[] array from left to right
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }

        // Step 2: Populate the dec[] array from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }

        // Step 3: Find the maximum value of inc[i] + dec[i] - 1
        int max_len = inc[0] + dec[0] - 1;
        for (int i = 1; i < n; i++) {
            max_len = max(max_len, inc[i] + dec[i] - 1);
        }

        return max_len;
    }
};