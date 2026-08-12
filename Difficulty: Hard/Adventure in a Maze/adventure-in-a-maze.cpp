#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1e9 + 7;

        // count[i][j] stores the number of valid paths to grid[i][j]
        vector<vector<long long>> count(n, vector<long long>(n, 0));
        
        // max_adv[i][j] stores the maximum adventure path sum to grid[i][j]
        vector<vector<int>> max_adv(n, vector<int>(n, -1));

        // Base case: starting cell (0, 0)
        count[0][0] = 1;
        max_adv[0][0] = grid[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip starting cell or unreachable cells
                if (count[i][j] == 0 && (i != 0 || j != 0)) continue;

                int current_val = grid[i][j];

                // Check if we can move DOWN to (i + 1, j)
                if ((current_val == 2 || current_val == 3) && i + 1 < n) {
                    count[i + 1][j] = (count[i + 1][j] + count[i][j]) % MOD;
                    max_adv[i + 1][j] = max(max_adv[i + 1][j], max_adv[i][j] + grid[i + 1][j]);
                }

                // Check if we can move RIGHT to (i, j + 1)
                if ((current_val == 1 || current_val == 3) && j + 1 < n) {
                    count[i][j + 1] = (count[i][j + 1] + count[i][j]) % MOD;
                    max_adv[i][j + 1] = max(max_adv[i][j + 1], max_adv[i][j] + grid[i][j + 1]);
                }
            }
        }

        // If the bottom-right cell is unreachable
        if (count[n - 1][n - 1] == 0) {
            return {0, 0};
        }

        return {(int)count[n - 1][n - 1], max_adv[n - 1][n - 1]};
    }
};