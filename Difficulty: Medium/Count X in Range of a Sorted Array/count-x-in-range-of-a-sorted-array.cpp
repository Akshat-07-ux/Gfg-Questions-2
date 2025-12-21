class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];
            
            // First occurrence of x in entire array
            int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            
            // x not present
            if (left == arr.size() || arr[left] != x) {
                ans.push_back(0);
                continue;
            }
            
            // Last occurrence of x in entire array
            int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
            
            // Intersect with [l, r]
            int L = max(left, l);
            int R = min(right, r);
            
            if (L > R)
                ans.push_back(0);
            else
                ans.push_back(R - L + 1);
        }
        
        return ans;
    }
};
