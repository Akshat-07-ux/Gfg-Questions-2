class Solution {
  public:
    void sortHalves(int arr[], int n) {
        if (n <= 1) return;

        // 1. Find the split point where the second sorted half starts
        int mid = n; // Default if the whole array is already one sorted half
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                mid = i;
                break;
            }
        }

        // If no split point was found, the array is already sorted
        if (mid == n) return;

        // 2. Merge the two halves using a temporary array
        int temp[n];
        int i = 0;        // Pointer for first half [0...mid-1]
        int j = mid;      // Pointer for second half [mid...n-1]
        int k = 0;        // Pointer for temp array

        while (i < mid && j < n) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        // 3. Copy remaining elements from the first half, if any
        while (i < mid) {
            temp[k++] = arr[i++];
        }

        // 4. Copy remaining elements from the second half, if any
        while (j < n) {
            temp[k++] = arr[j++];
        }

        // 5. Copy temp back to original array
        for (int x = 0; x < n; x++) {
            arr[x] = temp[x];
        }
    }
};