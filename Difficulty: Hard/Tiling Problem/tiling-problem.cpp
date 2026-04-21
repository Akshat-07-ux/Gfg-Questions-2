#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int tileNum = 1;

    void solve(int n, int row, int col, int holeRow, int holeCol, vector<vector<int>> &grid) {
        if (n == 1) return;

        int size = n / 2;
        int currentTile = tileNum++;
        
        // Midpoints to determine quadrants
        int midRow = row + size;
        int midCol = col + size;

        // Top-Left Quadrant
        if (holeRow < midRow && holeCol < midCol) {
            // Hole is in this quadrant
            solve(size, row, col, holeRow, holeCol, grid);
        } else {
            // Place tile at the corner near center and recurse
            grid[midRow - 1][midCol - 1] = currentTile;
            solve(size, row, col, midRow - 1, midCol - 1, grid);
        }

        // Top-Right Quadrant
        if (holeRow < midRow && holeCol >= midCol) {
            solve(size, row, midCol, holeRow, holeCol, grid);
        } else {
            grid[midRow - 1][midCol] = currentTile;
            solve(size, row, midCol, midRow - 1, midCol, grid);
        }

        // Bottom-Left Quadrant
        if (holeRow >= midRow && holeCol < midCol) {
            solve(size, midRow, col, holeRow, holeCol, grid);
        } else {
            grid[midRow][midCol - 1] = currentTile;
            solve(size, midRow, col, midRow, midCol - 1, grid);
        }

        // Bottom-Right Quadrant
        if (holeRow >= midRow && holeCol >= midCol) {
            solve(size, midRow, midCol, holeRow, holeCol, grid);
        } else {
            grid[midRow][midCol] = currentTile;
            solve(size, midRow, midCol, midRow, midCol, grid);
        }
    }

public:
    void fillTile(int n, vector<vector<int>> &grid) {
        int holeRow = -1, holeCol = -1;
        
        // Find the initial missing cell (-1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    holeRow = i;
                    holeCol = j;
                    break;
                }
            }
            if (holeRow != -1) break;
        }

        tileNum = 1; // Reset tile counter for each call
        solve(n, 0, 0, holeRow, holeCol, grid);
    }
};