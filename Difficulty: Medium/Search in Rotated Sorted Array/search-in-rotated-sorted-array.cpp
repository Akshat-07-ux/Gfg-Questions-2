class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return mid;
            }

            // Identify which half is sorted
            if (arr[low] <= arr[mid]) {
                // Left half [low...mid] is sorted
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1; // Key is in the left half
                } else {
                    low = mid + 1;  // Key is in the right half
                }
            } else {
                // Right half [mid...high] is sorted
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;  // Key is in the right half
                } else {
                    high = mid - 1; // Key is in the left half
                }
            }
        }

        return -1; // Key not found
    }
};