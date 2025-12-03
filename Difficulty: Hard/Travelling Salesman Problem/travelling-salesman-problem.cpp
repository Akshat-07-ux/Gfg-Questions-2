class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int FULL = (1 << n);

        // dp[mask][i] = min cost to reach city i having visited cities in mask
        vector<vector<int>> dp(FULL, vector<int>(n, 1e9));

        dp[1][0] = 0; // starting at city 0, mask = 1<<0

        for (int mask = 0; mask < FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue; // i must be in mask

                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue; // j not yet visited
                    int nextMask = mask | (1 << j);
                    dp[nextMask][j] = min(dp[nextMask][j], dp[mask][i] + cost[i][j]);
                }
            }
        }

        int ans = 1e9;
        int finalMask = FULL - 1;

        // End at any city i, and return to 0
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[finalMask][i] + cost[i][0]);
        }

        return ans;
    }
};
