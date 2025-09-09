#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // Step 1: sort both arrays
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int n = mices.size();
        int ans = 0;
        
        // Step 2: assign ith mouse to ith hole
        for (int i = 0; i < n; i++) {
            ans = max(ans, abs(mices[i] - holes[i]));
        }
        
        return ans;
    }
};
