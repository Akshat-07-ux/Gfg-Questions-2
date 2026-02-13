class Solution {
  public:
    // Function to search a given integer in a matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int rows = mat.size();
        if (rows == 0) return false;
        int cols = mat[0].size();

        // Standard 2D traversal
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == x) {
                    return true;
                }
            }
        }

        return false;
    }
};