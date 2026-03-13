class Solution {
  public:
    int minDiff(vector<int>& arr, int k, int m, int t) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int count = 0;
        
        // Count ≥ t in first window
        for(int i = 0; i < k; i++) {
            if(arr[i] >= t) count++;
        }
        
        int ans = INT_MAX;
        
        if(count >= m)
            ans = arr[k-1] - arr[0];
        
        // Sliding window
        for(int i = k; i < n; i++) {
            
            if(arr[i-k] >= t) count--;
            if(arr[i] >= t) count++;
            
            if(count >= m) {
                ans = min(ans, arr[i] - arr[i-k+1]);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};