#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        // boundary + condition check
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O')
            return;

        // mark as safe
        grid[i][j] = 'B';

        // explore 4 directions
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }

    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return;
        int m = grid[0].size();

        // Step 1: DFS from all border 'O's
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 'O') dfs(grid, i, m - 1, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') dfs(grid, 0, j, n, m);
            if (grid[n - 1][j] == 'O') dfs(grid, n - 1, j, n, m);
        }

        // Step 2: Flip surrounded and restore safe cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O')
                    grid[i][j] = 'X'; // surrounded region
                else if (grid[i][j] == 'B')
                    grid[i][j] = 'O'; // restore safe ones
            }
        }
    }
};
