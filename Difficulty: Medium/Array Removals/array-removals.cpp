class Solution {
  public:
    int removals(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        int i = 0;
        int maxLen = 0;
        
        // Step 2: Sliding window
        for (int j = 0; j < n; j++) {
            while (arr[j] - arr[i] > k) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        
        // Step 3: Minimum removals
        return n - maxLen;
    }
};
