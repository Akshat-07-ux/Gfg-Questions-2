#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // Helper function to perform BFS from the boundary cells inward
    void bfs(const vector<vector<int>>& mat, queue<pair<int, int>>& q, vector<vector<bool>>& reachable, int n, int m) {
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                
                // Check boundaries and if the cell has already been visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !reachable[nr][nc]) {
                    // Reverse condition: next cell must have >= signal strength
                    if (mat[nr][nc] >= mat[r][c]) {
                        reachable[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

public:
    int countCoordinates(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
        
        queue<pair<int, int>> qP;
        queue<pair<int, int>> qQ;
        
        // 1. Add top and bottom rows to their respective queues
        for (int j = 0; j < m; j++) {
            // Top row for Station P
            reachP[0][j] = true;
            qP.push({0, j});
            
            // Bottom row for Station Q
            reachQ[n - 1][j] = true;
            qQ.push({n - 1, j});
        }
        
        // 2. Add left and right columns to their respective queues
        for (int i = 0; i < n; i++) {
            // Left column for Station P
            if (!reachP[i][0]) {
                reachP[i][0] = true;
                qP.push({i, 0});
            }
            
            // Right column for Station Q
            if (!reachQ[i][m - 1]) {
                reachQ[i][m - 1] = true;
                qQ.push({i, m - 1});
            }
        }
        
        // 3. Run BFS inward for both stations
        bfs(mat, qP, reachP, n, m);
        bfs(mat, qQ, reachQ, n, m);
        
        // 4. Count cells that can reach both stations
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reachP[i][j] && reachQ[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};