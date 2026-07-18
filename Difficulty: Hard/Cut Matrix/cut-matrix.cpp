#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int MOD = 1e9 + 7;

        // 2D Prefix Sum to count 1s efficiently
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pref[i + 1][j + 1] = matrix[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }

        auto getOnes = [&](int r, int c) {
            return pref[n][m] - pref[r][m] - pref[n][c] + pref[r][c];
        };

        // Precompute the earliest row/col that contains a '1' starting from (r, c)
        vector<vector<int>> cut_r(n, vector<int>(m, n));
        vector<vector<int>> cut_c(n, vector<int>(m, m));

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                // Find first row >= r containing a 1 in columns [c, m-1]
                for (int i = r; i < n; ++i) {
                    if (getOnes(r, c) - getOnes(i + 1, c) > 0) {
                        cut_r[r][c] = i;
                        break;
                    }
                }
                // Find first col >= c containing a 1 in rows [r, n-1]
                for (int j = c; j < m; ++j) {
                    if (getOnes(r, c) - getOnes(r, j + 1) > 0) {
                        cut_c[r][c] = j;
                        break;
                    }
                }
            }
        }

        // dp[r][c][rem] stores ways to cut submatrix (r,c) to (n-1,m-1) into 'rem' pieces
        // To optimize space, we only need the previous layer (rem - 1)
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> sum_h(n + 1, vector<int>(m, 0));
        vector<vector<int>> sum_v(n, vector<int>(m + 1, 0));

        // Base case: rem = 1 piece
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                dp[r][c] = (getOnes(r, c) > 0) ? 1 : 0;
            }
        }

        // Build suffix sums for the base case
        for (int c = 0; c < m; ++c) {
            for (int r = n - 1; r >= 0; --r) {
                sum_h[r][c] = (sum_h[r + 1][c] + dp[r][c]) % MOD;
            }
        }
        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                sum_v[r][c] = (sum_v[r][c + 1] + dp[r][c]) % MOD;
            }
        }

        // DP transitions for rem = 2 to k
        for (int rem = 2; rem <= k; ++rem) {
            vector<vector<int>> next_dp(n, vector<int>(m, 0));

            for (int r = n - 1; r >= 0; --r) {
                for (int c = m - 1; c >= 0; --c) {
                    if (getOnes(r, c) == 0) continue;

                    long long ways = 0;

                    // 1. Horizontal Cuts: valid from cut_r[r][c] to n-2
                    int i_min = cut_r[r][c];
                    if (i_min <= n - 2) {
                        ways = (ways + sum_h[i_min + 1][c]) % MOD;
                    }

                    // 2. Vertical Cuts: valid from cut_c[r][c] to m-2
                    int j_min = cut_c[r][c];
                    if (j_min <= m - 2) {
                        ways = (ways + sum_v[r][j_min + 1]) % MOD;
                    }

                    next_dp[r][c] = ways;
                }
            }

            dp = move(next_dp);

            // Refresh suffix sums for the next iteration
            for (int c = 0; c < m; ++c) {
                sum_h[n][c] = 0;
                for (int r = n - 1; r >= 0; --r) {
                    sum_h[r][c] = (sum_h[r + 1][c] + dp[r][c]) % MOD;
                }
            }
            for (int r = 0; r < n; ++r) {
                sum_v[r][m] = 0;
                for (int c = m - 1; c >= 0; --c) {
                    sum_v[r][c] = (sum_v[r][c + 1] + dp[r][c]) % MOD;
                }
            }
        }

        return dp[0][0];
    }
};