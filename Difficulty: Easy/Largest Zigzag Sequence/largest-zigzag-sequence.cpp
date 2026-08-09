#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 1) return mat[0][0];

        // prev[j] stores the max path sum ending at the previous row, column j
        vector<int> prev = mat[0];

        for (int i = 1; i < n; ++i) {
            // Find the top two maximum values in the previous row
            int first_max = -1, second_max = -1;
            int first_max_col = -1;

            for (int j = 0; j < n; ++j) {
                if (prev[j] > first_max) {
                    second_max = first_max;
                    first_max = prev[j];
                    first_max_col = j;
                } else if (prev[j] > second_max) {
                    second_max = prev[j];
                }
            }

            // Calculate the max path sum for the current row
            vector<int> curr(n);
            for (int j = 0; j < n; ++j) {
                if (j == first_max_col) {
                    curr[j] = mat[i][j] + second_max;
                } else {
                    curr[j] = mat[i][j] + first_max;
                }
            }

            prev = move(curr);
        }

        // Return the maximum value from the last row's DP array
        return *max_element(prev.begin(), prev.end());
    }
};