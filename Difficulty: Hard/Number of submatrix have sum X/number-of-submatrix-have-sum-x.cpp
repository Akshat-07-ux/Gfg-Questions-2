class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        
        // pref[i][j] will store the sum of the submatrix from (0,0) to (i-1, j-1)
        vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
        
        // Precompute the 2D prefix sum
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        
        int count = 0;
        
        // Iterate through every possible side length k
        // The maximum possible side length is the minimum of n and m
        int max_k = min(n, m);
        
        for (int k = 1; k <= max_k; k++) {
            // Iterate through every possible top-left corner (i, j)
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= m - k; j++) {
                    // Coordinates of the bottom-right corner (r2, c2)
                    int r2 = i + k - 1;
                    int c2 = j + k - 1;
                    
                    // Calculate sum of square submatrix in O(1)
                    long long currentSum = pref[r2+1][c2+1] - pref[i][c2+1] - pref[r2+1][j] + pref[i][j];
                    
                    if (currentSum == x) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};