#include <vector>
#include <algorithm>

class Solution {
  public:
    int altProduct(std::vector<int>& arr) {
        // Sort the array to easily pair largest with smallest
        std::sort(arr.begin(), arr.end());
        
        long long minProductSum = 0;
        int n = arr.size();
        
        // Two-pointer approach to pair elements
        for (int i = 0; i < n / 2; i++) {
            minProductSum += (long long)arr[i] * arr[n - 1 - i];
        }
        
        return static_cast<int>(minProductSum);
    }
};