// Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>> A) {
        int n = A.size();
        int row = 0;
        int col = n - 1;
        int count = 0;
        
        while (row < n && col >= 0) {
            if (A[row][col] == 0) {
                // All elements from 0 to col in this row are zeros
                count += (col + 1);
                row++;  // Move to next row
            } else {
                col--;  // Move left
            }
        }
        
        return count;
    }
};
