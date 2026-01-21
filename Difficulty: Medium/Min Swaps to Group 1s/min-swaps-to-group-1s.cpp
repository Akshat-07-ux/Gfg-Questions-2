class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int K = 0;

        // Step 1: Count total number of 1s
        for (int x : arr) {
            if (x == 1) K++;
        }

        // Step 2: Handle edge case where no 1s are present
        if (K == 0) return -1;

        // Step 3: Use sliding window to find the max number of 1s in a window of size K
        int current_ones = 0;
        int max_ones = 0;

        // Initialize the first window
        for (int i = 0; i < K; i++) {
            if (arr[i] == 1) current_ones++;
        }
        max_ones = current_ones;

        // Slide the window across the array
        for (int i = K; i < n; i++) {
            // Add the new element entering the window
            if (arr[i] == 1) current_ones++;
            // Remove the element leaving the window
            if (arr[i - K] == 1) current_ones--;

            max_ones = max(max_ones, current_ones);
        }

        // Step 4: Minimum swaps = total 1s - max 1s found in any window
        return K - max_ones;
    }
};