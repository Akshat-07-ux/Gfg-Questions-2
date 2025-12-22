class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int maxOnes = 0;
        int ans = -1;
        
        for (int i = 0; i < n; i++) {
            // Find first occurrence of 1 using binary search
            int idx = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
            
            int countOnes = m - idx;
            
            if (countOnes > maxOnes) {
                maxOnes = countOnes;
                ans = i;
            }
        }
        
        return ans;
    }
};
