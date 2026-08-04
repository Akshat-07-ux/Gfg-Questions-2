class Solution {
  public:
    long long countPairs(vector<int>& arr, int k) {
        int n = arr.size();
        
        // If k <= 0, no positive difference can be strictly less than k
        if (k <= 0) return 0;

        // Sort the array to use the two-pointer approach
        sort(arr.begin(), arr.end());

        long long count = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Shrink the window from the left until the difference is strictly less than k
            while (arr[right] - arr[left] >= k) {
                left++;
            }
            // All elements between 'left' and 'right-1' form a valid pair with arr[right]
            count += (right - left);
        }

        return count;
    }
};