class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {};

        // leftMin[i] will store the minimum element occurring before index i
        vector<int> leftMin(n);
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }

        // rightMax[i] will store the maximum element occurring after index i
        vector<int> rightMax(n);
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        // Find an element that has a smaller number to its left 
        // and a larger number to its right
        for (int j = 0; j < n; j++) {
            if (arr[j] > leftMin[j] && arr[j] < rightMax[j]) {
                return {leftMin[j], arr[j], rightMax[j]};
            }
        }

        // If no such triplet exists
        return {};
    }
};