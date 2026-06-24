#include <vector>

using namespace std;

class Solution {
  private:
    bool solve(int i, int j, int n, vector<vector<int>>& mat, vector<vector<int>>& sol, vector<vector<int>>& memo) {
        // Destination reached
        if (i == n - 1 && j == n - 1) {
            sol[i][j] = 1;
            return true;
        }

        // Check if current cell is out of bounds or blocked
        if (i >= n || j >= n || mat[i][j] == 0) {
            return false;
        }

        // If we have already evaluated this cell and it failed previously, return false
        if (memo[i][j] == -1) {
            return false;
        }

        // Mark the current cell as part of the tentative solution path
        sol[i][j] = 1;

        int maxJumps = mat[i][j];

        // Explore jumps from 1 up to maxJumps
        // Preference 1: Shortest jumps first
        for (int jump = 1; jump <= maxJumps; ++jump) {
            
            // Preference 2: Moving forward (Right) first
            if (j + jump < n) {
                if (solve(i, j + jump, n, mat, sol, memo)) {
                    return true;
                }
            }
            
            // Preference 2: Moving Downward second
            if (i + jump < n) {
                if (solve(i + jump, j, n, mat, sol, memo)) {
                    return true;
                }
            }
        }

        // Backtrack: Unmark current cell
        sol[i][j] = 0;
        
        // Memoize: Mark this cell as -1 because no valid path exists from here
        memo[i][j] = -1;
        
        return false;
    }

  public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Final solution matrix initialized with 0s
        vector<vector<int>> sol(n, vector<int>(n, 0));
        
        // memo[i][j] = 0 means unvisited, -1 means it's a dead end
        vector<vector<int>> memo(n, vector<int>(n, 0));

        // Edge case: standard starting cell check
        if (n > 1 && mat[0][0] == 0) {
            return {{-1}};
        }

        if (solve(0, 0, n, mat, sol, memo)) {
            return sol;
        }

        return {{-1}};
    }
};