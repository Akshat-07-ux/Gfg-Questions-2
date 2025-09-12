#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;
        
        sort(arr.begin(), arr.end());
        
        int ans = arr[n-1] - arr[0];  // initial difference
        
        for (int i = 0; i < n-1; i++) {
            int mn = min(arr[0] + k, arr[i+1] - k);
            int mx = max(arr[i] + k, arr[n-1] - k);
            
            if (mn < 0) continue;  // heights can't be negative
            
            ans = min(ans, mx - mn);
        }
        
        return ans;
    }
};
