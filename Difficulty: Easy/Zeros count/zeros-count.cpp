class Solution {
  public:
    int countZeroes(int arr[], int n) {
        int low = 0;
        int high = n - 1;
        int firstZeroIndex = n; // Default if no zeros are found

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == 0) {
                // Potential first zero, store index and look left
                firstZeroIndex = mid;
                high = mid - 1;
            } else {
                // It's a 1, so the first zero must be to the right
                low = mid + 1;
            }
        }

        // Total elements - index of the first zero = number of zeros
        return n - firstZeroIndex;
    }
};