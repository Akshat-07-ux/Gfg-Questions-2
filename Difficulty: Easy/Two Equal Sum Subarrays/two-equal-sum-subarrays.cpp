class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        long long totalSum = 0;
        
        // Calculate the sum of all elements
        for (int num : arr) {
            totalSum += num;
        }
        
        // If the total sum is odd, we can't split it into two equal integer sums
        if (totalSum % 2 != 0) {
            return false;
        }
        
        long long target = totalSum / 2;
        long long currentSum = 0;
        
        // Iterate through the array to find the split point
        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            
            if (currentSum == target) {
                return true;
            }
            
            // Optimization: if currentSum exceeds target, 
            // and since elements are >= 1, no need to look further
            if (currentSum > target) {
                return false;
            }
        }
        
        return false;
    }
};