#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // Helper function to perform BFS and eliminate connected components
    void bfs(int startX, int startY, vector<vector<int>>& grid, int n, int m) {
        queue<pair<int, int>> q;
        q.push({startX, startY});
        grid[startX][startY] = 0; // Mark as visited by turning it to 0
        
        // Directions for Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // If adjacent cell is within bounds and is a '1', it can escape too
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0; // Mark as visited
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int cntOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        // Step 1: Traverse the boundary cells and trigger BFS for any '1' found.
        // This eliminates all escapable paths.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if it's a boundary cell
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        bfs(i, j, grid, n, m);
                    }
                }
            }
        }
        
        // Step 2: Count the remaining '1's which are completely trapped.
        int trappedOnes = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    trappedOnes++;
                }
            }
        }
        
        return trappedOnes;
    }
};