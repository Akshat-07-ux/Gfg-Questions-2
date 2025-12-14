class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();

        // Prefix sum matrix
        vector<vector<long long>> pref(n, vector<long long>(m, 0));

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] = mat[i][j];
                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
            }
        }

        vector<int> result;

        // Process queries
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

            long long sum = pref[r2][c2];
            if (r1 > 0) sum -= pref[r1 - 1][c2];
            if (c1 > 0) sum -= pref[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += pref[r1 - 1][c1 - 1];

            result.push_back(sum);
        }

        return result;
    }
};
