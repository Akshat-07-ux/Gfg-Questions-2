#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;

        int prev2 = 0;  // cost for i-2
        int prev1 = abs(height[1] - height[0]); // cost for i-1

        for (int i = 2; i < n; i++) {
            int jumpOne = prev1 + abs(height[i] - height[i - 1]);
            int jumpTwo = prev2 + abs(height[i] - height[i - 2]);
            int curr = min(jumpOne, jumpTwo);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

