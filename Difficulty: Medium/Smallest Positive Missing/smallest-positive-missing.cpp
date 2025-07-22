class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Remove non-positive numbers by replacing them with a number greater than n
        for(int i = 0; i < n; i++) {
            if(arr[i] <= 0 || arr[i] > n) {
                arr[i] = n + 1;
            }
        }

        // Step 2: Use index marking to record the presence of elements
        for(int i = 0; i < n; i++) {
            int val = abs(arr[i]);
            if(val >= 1 && val <= n) {
                if(arr[val - 1] > 0) {
                    arr[val - 1] = -arr[val - 1];
                }
            }
        }

        // Step 3: Find the first missing positive number
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                return i + 1;
            }
        }

        // If all 1..n are present, return n+1
        return n + 1;
    }
};
