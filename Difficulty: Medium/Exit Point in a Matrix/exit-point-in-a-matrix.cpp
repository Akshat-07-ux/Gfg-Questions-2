#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Direction vectors: Right, Down, Left, Up
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        // Initial state
        int r = 0, c = 0;
        int dir = 0; // 0: Right, 1: Down, 2: Left, 3: Up
        
        while (true) {
            // If we encounter a 1, change direction clockwise and flip the cell to 0
            if (mat[r][c] == 1) {
                dir = (dir + 1) % 4;
                mat[r][c] = 0;
            }
            
            // Calculate the next potential position
            int next_r = r + dr[dir];
            int next_c = c + dc[dir];
            
            // If the next position is outside the matrix, we exit from the current cell
            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
                return {r, c};
            }
            
            // Otherwise, move to the next cell
            r = next_r;
            c = next_c;
        }
    }
};