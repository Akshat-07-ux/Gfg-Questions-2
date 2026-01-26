class Solution {
public:
    int Maximum_Sum(vector<vector<int>> &mat, int N, int K) {
        // Create a 2D prefix sum array (1-based indexing simplifies boundary checks)
        // Using long long for prefix sums to avoid overflow if constraints were larger, 
        // but int is sufficient for the given constraints.
        vector<vector<int>> pref(N + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // Calculate prefix sum: current + top + left - diagonal top-left
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        int max_sum = INT_MIN;

        // Iterate through all possible bottom-right corners (i, j) of a KxK sub-grid
        for (int i = K; i <= N; i++) {
            for (int j = K; j <= N; j++) {
                // Use the inclusion-exclusion formula to get the sum of the KxK square
                int current_sum = pref[i][j] - pref[i-K][j] - pref[i][j-K] + pref[i-K][j-K];
                
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                }
            }
        }

        return max_sum;
    }
};