class Solution {
  private:
    // Helper function to count subarrays with sum <= k using Sliding Window
    long long countSubarraysWithSumLessOrEqual(const vector<int>& arr, long long k) {
        if (k < 0) return 0;

        long long count = 0;
        long long current_sum = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); ++right) {
            current_sum += arr[right];

            // Shrink window from left until sum <= k
            while (left <= right && current_sum > k) {
                current_sum -= arr[left];
                left++;
            }

            // All subarrays ending at 'right' starting from indices 'left' to 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }

  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        long long atMostR = countSubarraysWithSumLessOrEqual(arr, r);
        long long atMostLMinus1 = countSubarraysWithSumLessOrEqual(arr, l - 1);
        
        return atMostR - atMostLMinus1;
    }
};