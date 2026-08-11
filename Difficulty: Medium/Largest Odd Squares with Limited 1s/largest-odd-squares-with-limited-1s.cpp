#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Build 2D Prefix Sum matrix
        // pref[i][j] stores the sum of elements in mat[0..i-1][0..j-1]
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pref[i + 1][j + 1] = mat[i][j] 
                                    + pref[i][j + 1] 
                                    + pref[i + 1][j] 
                                    - pref[i][j];
            }
        }
        
        // Helper lambda to query sum in O(1)
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
        };
        
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int row = q[0];
            int col = q[1];
            
            // Check if the 1x1 center square itself exceeds k ones
            if (mat[row][col] > k) {
                result.push_back(-1);
                continue;
            }
            
            // Maximum possible radius bounded by matrix borders
            int max_r = min({row, n - 1 - row, col, m - 1 - col});
            
            int low = 0, high = max_r;
            int best_r = 0;
            
            // Binary search for the maximum valid radius
            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                int r1 = row - mid;
                int c1 = col - mid;
                int r2 = row + mid;
                int c2 = col + mid;
                
                int onesCount = getSum(r1, c1, r2, c2);
                
                if (onesCount <= k) {
                    best_r = mid;
                    low = mid + 1; // Try expanding further
                } else {
                    high = mid - 1; // Shrink the square
                }
            }
            
            result.push_back(2 * best_r + 1);
        }
        
        return result;
    }
};