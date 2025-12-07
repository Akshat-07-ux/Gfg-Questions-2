class Solution {
  public:
    vector<int> printUnsorted(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        
        // Step 1: Find first break from left
        while (l < n - 1 && arr[l] <= arr[l + 1]) l++;
        if (l == n - 1) 
            return {0, 0};  // Already sorted
        
        // Step 2: Find first break from right
        while (r > 0 && arr[r] >= arr[r - 1]) r--;
        
        // Step 3: Find min and max in arr[l..r]
        int subMin = INT_MAX, subMax = INT_MIN;
        for (int i = l; i <= r; i++) {
            subMin = min(subMin, arr[i]);
            subMax = max(subMax, arr[i]);
        }
        
        // Step 4: Expand l
        while (l > 0 && arr[l - 1] > subMin) 
            l--;
        
        // Step 5: Expand r
        while (r < n - 1 && arr[r + 1] < subMax) 
            r++;
        
        return {l, r};
    }
};
