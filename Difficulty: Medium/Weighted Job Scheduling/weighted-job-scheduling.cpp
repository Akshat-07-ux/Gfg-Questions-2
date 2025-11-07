#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int n = jobs.size();
        vector<int> dp(n);          // dp[i] = max profit till job i
        vector<int> endTimes(n);    // store end times for binary search

        for (int i = 0; i < n; i++) endTimes[i] = jobs[i][1];

        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i][2];

            // Find last job that doesn't overlap using binary search
            int idx = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][0]) - endTimes.begin() - 1;

            if (idx >= 0)
                includeProfit += dp[idx];

            // Choose max of including or excluding the job
            dp[i] = max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }
};


