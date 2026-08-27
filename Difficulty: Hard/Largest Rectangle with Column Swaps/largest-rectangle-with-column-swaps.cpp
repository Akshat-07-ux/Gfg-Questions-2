#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Compute continuous 1s height for each column up to each row
        vector<vector<int>> hist(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            hist[0][j] = mat[0][j];
            for (int i = 1; i < n; ++i) {
                if (mat[i][j] == 1) {
                    hist[i][j] = hist[i - 1][j] + 1;
                } else {
                    hist[i][j] = 0;
                }
            }
        }

        int max_area = 0;

        // Step 2 & 3: Sort each row in descending order and compute max area
        for (int i = 0; i < n; ++i) {
            sort(hist[i].begin(), hist[i].end(), greater<int>());

            for (int j = 0; j < m; ++j) {
                int area = hist[i][j] * (j + 1);
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};