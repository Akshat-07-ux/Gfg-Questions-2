class Solution {
public:
    int n, m;
    int dp[71][71][71];

    int solve(int r, int c1, int c2, vector<vector<int>>& grid) {
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m) return -1e9;
        if (r == n) return 0;

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int ans = 0;

        // chocolates collected at this row
        if (c1 == c2) ans += grid[r][c1];
        else ans += grid[r][c1] + grid[r][c2];

        int best = 0;

        // 3 moves for each robot → 9 combinations
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                best = max(best, solve(r + 1, c1 + d1, c2 + d2, grid));
            }
        }

        return dp[r][c1][c2] = ans + best;
    }

    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));
        
        // Robot1 at (0,0), Robot2 at (0,m-1)
        return solve(0, 0, m - 1, grid);
    }
};
