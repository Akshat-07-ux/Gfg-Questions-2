class Solution {
  public:
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> ans;
        ans.reserve(n * n);

        for (int d = 0; d < 2 * n - 1; d++) {
            int row, col;

            if (d % 2 == 0) {
                // Even diagonal → move upwards
                row = min(d, n - 1);
                col = d - row;

                while (row >= 0 && col < n) {
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
            } else {
                // Odd diagonal → move downwards
                col = min(d, n - 1);
                row = d - col;

                while (col >= 0 && row < n) {
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};
