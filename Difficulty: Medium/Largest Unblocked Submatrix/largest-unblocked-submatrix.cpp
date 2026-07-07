#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // Step 1: Extract row and column blockages
        vector<int> rows;
        vector<int> cols;
        
        // Add virtual boundaries
        rows.push_back(0);
        rows.push_back(n + 1);
        cols.push_back(0);
        cols.push_back(m + 1);
        
        for (const auto& cell : arr) {
            rows.push_back(cell[0]);
            cols.push_back(cell[1]);
        }
        
        // Step 2: Sort the coordinates to find consecutive gaps
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        // Step 3: Find the maximum consecutive unblocked rows
        int max_row_gap = 0;
        for (size_t i = 1; i < rows.size(); ++i) {
            max_row_gap = max(max_row_gap, rows[i] - rows[i-1] - 1);
        }
        
        // Step 4: Find the maximum consecutive unblocked columns
        int max_col_gap = 0;
        for (size_t i = 1; i < cols.size(); ++i) {
            max_col_gap = max(max_col_gap, cols[i] - cols[i-1] - 1);
        }
        
        // Step 5: Return the maximum rectangle area
        return max_row_gap * max_col_gap;
    }
};