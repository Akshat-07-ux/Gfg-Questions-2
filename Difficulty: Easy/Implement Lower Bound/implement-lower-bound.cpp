class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size(); // Default to size if no element is >= target

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid;        // Candidate found, try to find a smaller index
                high = mid - 1;   // Search in the left half
            } else {
                low = mid + 1;    // Search in the right half
            }
        }

        return ans;
    }
};