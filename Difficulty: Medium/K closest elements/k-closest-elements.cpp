class Solution {
   public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
        
        // Find the index of the first element >= x using binary search
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;

        // Skip x if it exists in the array
        if (right < n && arr[right] == x) {
            right++;
        }

        vector<int> result;

        // Use two pointers to find the k closest elements
        while (k--) {
            if (left >= 0 && right < n) {
                int diffLeft = abs(arr[left] - x);
                int diffRight = abs(arr[right] - x);

                if (diffLeft < diffRight) {
                    result.push_back(arr[left--]);
                } else if (diffRight < diffLeft) {
                    result.push_back(arr[right++]);
                } else {
                    // Tie-breaking: prefer the larger element
                    if (arr[left] > arr[right]) {
                        result.push_back(arr[left--]);
                    } else {
                        result.push_back(arr[right++]);
                    }
                }
            } else if (left >= 0) {
                result.push_back(arr[left--]);
            } else {
                result.push_back(arr[right++]);
            }
        }

        return result;
    }
};