class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0;
        int right = 0;
        int zeroCount = 0;
        int maxLen = 0;
        int n = arr.size();

        while (right < n) {
            // If we encounter a 0, increment our zero counter
            if (arr[right] == 0) {
                zeroCount++;
            }

            // If zeroCount exceeds k, shrink the window from the left
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Calculate the current window size and update maxLen
            // Window size is (right - left + 1)
            maxLen = max(maxLen, right - left + 1);
            
            // Move the right pointer forward
            right++;
        }

        return maxLen;
    }
};