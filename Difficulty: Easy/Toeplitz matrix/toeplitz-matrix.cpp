class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Iterate through the matrix starting from the second row and second column
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                // Check if the current element is equal to its top-left neighbor
                if (mat[i][j] != mat[i - 1][j - 1]) {
                    return false;
                }
            }
        }

        // If no mismatches were found, it is a Toeplitz matrix
        return true;
    }
};