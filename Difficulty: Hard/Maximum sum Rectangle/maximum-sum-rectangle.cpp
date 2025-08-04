class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        for (int top = 0; top < n; ++top) {
            vector<int> temp(m, 0);  // temporary array to store column sums
            for (int bottom = top; bottom < n; ++bottom) {
                // Add the current row to temp
                for (int col = 0; col < m; ++col) {
                    temp[col] += mat[bottom][col];
                }

                // Apply Kadane's algorithm on temp array
                int currSum = temp[0];
                int maxCurrSum = temp[0];
                for (int i = 1; i < m; ++i) {
                    currSum = max(temp[i], currSum + temp[i]);
                    maxCurrSum = max(maxCurrSum, currSum);
                }

                maxSum = max(maxSum, maxCurrSum);
            }
        }

        return maxSum;
    }
};
