class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int totalOnes = 0;

        // Step 1: Count total number of 1s in the array
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }

        // Step 2: Edge case - no 1s present
        if (totalOnes == 0) return -1;

        // Step 3: Sliding window of size 'totalOnes'
        int currentOnes = 0;
        int maxOnesInWindow = 0;

        // Initial window
        for (int i = 0; i < totalOnes; i++) {
            if (arr[i] == 1) currentOnes++;
        }
        maxOnesInWindow = currentOnes;

        // Slide the window across the rest of the array
        for (int i = totalOnes; i < n; i++) {
            // Add the new element entering the window
            if (arr[i] == 1) currentOnes++;
            // Remove the element that is no longer in the window
            if (arr[i - totalOnes] == 1) currentOnes--;

            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }

        // Step 4: Minimum swaps = total 1s - maximum 1s already together
        return totalOnes - maxOnesInWindow;
    }
};