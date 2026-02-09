class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;

        // If the array is not rotated at all
        if (arr[low] <= arr[high]) return 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the minimum element
            // (Check mid+1 and mid-1 carefully to avoid index out of bounds)
            int next = (mid + 1) % arr.size();
            int prev = (mid + arr.size() - 1) % arr.size();

            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
                return mid;
            }

            // Decide which half to pick
            if (arr[mid] <= arr[high]) {
                // Right side is sorted, minimum is on the left
                high = mid - 1;
            } else {
                // Left side is sorted, minimum is on the right
                low = mid + 1;
            }
        }
        return 0;
    }
};