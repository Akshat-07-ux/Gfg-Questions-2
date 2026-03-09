class Solution {
  public:
    void backtrack(int i, int j, int n, int m, vector<vector<int>> &mat, 
                   vector<int> &currentPath, vector<vector<int>> &result) {
        
        // Add current cell to path
        currentPath.push_back(mat[i][j]);

        // If we reached the bottom-right corner
        if (i == n - 1 && j == m - 1) {
            result.push_back(currentPath);
        } else {
            // Move Down
            if (i + 1 < n) {
                backtrack(i + 1, j, n, m, mat, currentPath, result);
            }
            // Move Right
            if (j + 1 < m) {
                backtrack(i, j + 1, n, m, mat, currentPath, result);
            }
        }

        // Backtrack: remove the current cell before returning to the previous call
        currentPath.pop_back();
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &mat) {
        vector<vector<int>> result;
        vector<int> currentPath;
        
        if (n == 0 || m == 0) return result;
        
        backtrack(0, 0, n, m, mat, currentPath, result);
        return result;
    }
};