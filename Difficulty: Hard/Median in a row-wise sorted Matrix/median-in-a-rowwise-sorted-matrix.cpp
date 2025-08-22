#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSmallerEqual(vector<int> &row, int x) {
        // upper_bound returns iterator to first element greater than x
        return upper_bound(row.begin(), row.end(), x) - row.begin();
    }

    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Find minimum and maximum elements in matrix
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        
        int desired = (n * m + 1) / 2;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            
            // Count number of elements <= mid in each row
            for (int i = 0; i < n; i++) {
                count += countSmallerEqual(mat[i], mid);
            }
            
            if (count < desired) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
