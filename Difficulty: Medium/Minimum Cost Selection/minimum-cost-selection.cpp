#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // Initialize state with the costs of the first row
        int prev0 = mat[0][0];
        int prev1 = mat[0][1];
        int prev2 = mat[0][2];

        // Transition through remaining rows
        for (int i = 1; i < n; i++) {
            int curr0 = mat[i][0] + min(prev1, prev2);
            int curr1 = mat[i][1] + min(prev0, prev2);
            int curr2 = mat[i][2] + min(prev0, prev1);

            // Update previous choices for the next iteration
            prev0 = curr0;
            prev1 = curr1;
            prev2 = curr2;
        }

        // Return the minimum of the three choices at the last row
        return min({prev0, prev1, prev2});
    }
};