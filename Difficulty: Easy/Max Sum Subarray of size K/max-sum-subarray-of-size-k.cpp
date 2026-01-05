class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        long long windowSum = 0;
        
        // Build the first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        
        long long maxSum = windowSum;
        
        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            windowSum += arr[i];       // add next element
            windowSum -= arr[i - k];   // remove element leaving the window
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};
