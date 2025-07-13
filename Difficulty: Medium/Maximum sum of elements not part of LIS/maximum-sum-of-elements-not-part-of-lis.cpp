#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);

        // Compute LIS using DP
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // Find the length of LIS
        int lis_len = *max_element(dp.begin(), dp.end());

        // Trace one LIS to mark used elements
        vector<int> lis_indices(n, 0);
        int len = lis_len;
        int prev = 1e9;
        for(int i = n - 1; i >= 0; --i) {
            if(dp[i] == len && arr[i] < prev) {
                lis_indices[i] = 1;
                prev = arr[i];
                len--;
            }
        }

        // Sum all elements not part of LIS
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(!lis_indices[i])
                sum += arr[i];
        }
        return sum;
    }
};
