class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Helper function to calculate sum of ceilings
        auto computeSum = [&](int divisor) {
            int sum = 0;
            for (int num : arr) {
                sum += (num + divisor - 1) / divisor; // ceil(num / divisor)
            }
            return sum;
        };
        
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currentSum = computeSum(mid);
            
            if (currentSum <= k) {
                ans = mid;         // possible answer, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // too small divisor, increase it
            }
        }
        
        return ans;
    }
};