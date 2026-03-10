class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        // 1. Build 2D Prefix Sum matrix
        vector<vector<int>> pref(R + 1, vector<int>(C + 1, 0));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                pref[i + 1][j + 1] = M[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
        };

        vector<int> results;
        for (int k = 0; k < Q; k++) {
            int r = q_i[k];
            int c = q_j[k];

            // Maximum possible "radius" based on distance to edges
            int max_d = min({r, c, R - 1 - r, C - 1 - c});
            
            int low = 0, high = max_d;
            int ans = 0;

            // 2. Binary Search for the largest valid radius d
            while (low <= high) {
                int d = low + (high - low) / 2;
                int r1 = r - d, c1 = c - d;
                int r2 = r + d, c2 = c + d;

                if (getSum(r1, c1, r2, c2) <= K) {
                    ans = 2 * d + 1; // Side length is 2*d + 1
                    low = d + 1;
                } else {
                    high = d - 1;
                }
            }
            results.push_back(ans);
        }

        return results;
    }
};