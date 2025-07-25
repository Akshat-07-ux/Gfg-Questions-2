class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        
        // Standard Kadane's algorithm to find max subarray sum
        int max_ending_here = arr[0], max_so_far = arr[0];
        int min_ending_here = arr[0], min_so_far = arr[0];
        int total_sum = arr[0];
        
        for(int i = 1; i < n; i++) {
            // For max subarray sum
            max_ending_here = max(arr[i], max_ending_here + arr[i]);
            max_so_far = max(max_so_far, max_ending_here);
            
            // For min subarray sum
            min_ending_here = min(arr[i], min_ending_here + arr[i]);
            min_so_far = min(min_so_far, min_ending_here);
            
            // Total sum of array
            total_sum += arr[i];
        }
        
        // If all elements are negative, max_so_far is the answer
        if (max_so_far < 0)
            return max_so_far;
        
        // Otherwise, return the maximum of non-wrapping and wrapping cases
        return max(max_so_far, total_sum - min_so_far);
    }
};
