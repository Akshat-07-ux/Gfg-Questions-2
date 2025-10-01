#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(arr.size(), false);

        sort(arr.begin(), arr.end()); // sort for lexicographic order
        
        function<void()> backtrack = [&]() {
            if (curr.size() == arr.size()) {
                ans.push_back(curr);
                return;
            }
            for (int i = 0; i < arr.size(); i++) {
                if (used[i]) continue;
                
                // skip duplicates
                if (i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue;
                
                used[i] = true;
                curr.push_back(arr[i]);
                backtrack();
                curr.pop_back();
                used[i] = false;
            }
        };
        
        backtrack();
        return ans;
    }
};


