#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
  public:
    int equalizeArray(vector<int>& arr, int k) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Step 1: Check feasibility using remainders
        int targetRemainder = (arr[0] % k + k) % k; // Handle potential negative values safely
        for (int i = 1; i < n; i++) {
            if ((arr[i] % k + k) % k != targetRemainder) {
                return -1;
            }
        }

        // Step 2: Find the median by sorting
        sort(arr.begin(), arr.end());
        int median = arr[n / 2];

        // Step 3: Accumulate the minimum operations to reach the median
        long long totalOps = 0;
        for (int i = 0; i < n; i++) {
            totalOps += abs(arr[i] - median) / k;
        }

        return static_cast<int>(totalOps);
    }
};