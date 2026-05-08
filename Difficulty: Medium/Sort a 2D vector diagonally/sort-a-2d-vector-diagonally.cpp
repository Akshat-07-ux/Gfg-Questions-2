#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void diagonalSort(vector<vector<int>>& matrix, int n, int m) {
        // 1. Sort Lower Left Triangle (Ascending)
        // Diagonals starting from matrix[1...n-1][0]
        for (int r = 1; r < n; r++) {
            vector<int> diagonal;
            int i = r, j = 0;
            // Extract elements
            while (i < n && j < m) {
                diagonal.push_back(matrix[i][j]);
                i++; j++;
            }
            // Sort Ascending
            sort(diagonal.begin(), diagonal.end());
            // Put back
            i = r; j = 0;
            int k = 0;
            while (i < n && j < m) {
                matrix[i][j] = diagonal[k++];
                i++; j++;
            }
        }

        // 2. Sort Upper Right Triangle (Descending)
        // Diagonals starting from matrix[0][1...m-1]
        for (int c = 1; c < m; c++) {
            vector<int> diagonal;
            int i = 0, j = c;
            // Extract elements
            while (i < n && j < m) {
                diagonal.push_back(matrix[i][j]);
                i++; j++;
            }
            // Sort Descending
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            // Put back
            i = 0; j = c;
            int k = 0;
            while (i < n && j < m) {
                matrix[i][j] = diagonal[k++];
                i++; j++;
            }
        }
        
        // Note: The major diagonal (i-j == 0) is naturally skipped 
        // as our loops start from index 1 for both rows and columns.
    }
};