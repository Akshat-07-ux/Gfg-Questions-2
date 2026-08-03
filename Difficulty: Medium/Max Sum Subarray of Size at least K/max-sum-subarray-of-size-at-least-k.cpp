#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
  public:
    int maxSumWithK(std::vector<int>& arr, int k) {
        int n = arr.size();
        
        // Step 1: Precompute Kadane's max subarray sum ending at each index
        std::vector<int> maxEnd(n);
        int current_max = arr[0];
        maxEnd[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            current_max = std::max(arr[i], current_max + arr[i]);
            maxEnd[i] = current_max;
        }
        
        // Step 2: Compute sum of first window of size k
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        int result = sum;
        
        // Step 3: Slide the window of length at least k across the array
        for (int i = k; i < n; i++) {
            sum = sum + arr[i] - arr[i - k];
            
            // Maximum sum for a subarray ending at i with length >= k is either:
            // 1. Just the sum of the last k elements (sum)
            // 2. The sum of the last k elements + max sum of valid subarray ending at (i - k)
            result = std::max(result, sum);
            result = std::max(result, sum + maxEnd[i - k]);
        }
        
        return result;
    }
};