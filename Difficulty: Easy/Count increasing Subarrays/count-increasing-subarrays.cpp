class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;

        int totalCount = 0;
        int currentLength = 1;

        for (int i = 0; i < n - 1; i++) {
            // Check if the next element continues the strictly increasing sequence
            if (arr[i + 1] > arr[i]) {
                currentLength++;
            } else {
                // If the sequence breaks, calculate subarrays for the finished segment
                if (currentLength >= 2) {
                    totalCount += (currentLength * (currentLength - 1)) / 2;
                }
                // Reset length for the new potential sequence
                currentLength = 1;
            }
        }

        // Final check for the last segment in the array
        if (currentLength >= 2) {
            totalCount += (currentLength * (currentLength - 1)) / 2;
        }

        return totalCount;
    }
};