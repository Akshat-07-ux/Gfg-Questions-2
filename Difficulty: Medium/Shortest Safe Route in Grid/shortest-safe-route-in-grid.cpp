class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        int a = mat.size();
        int b = mat[0].size();
        
        vector<vector<bool>> safe(a, vector<bool>(b, true));
        
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (mat[i][j] == 0) {
                    safe[i][j] = false;
                    int dr[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (ni >= 0 && ni < a && nj >= 0 && nj < b) {
                            safe[ni][nj] = false;
                        }
                    }
                }
            }
        }
        
        queue<pair<int, int>> q;
        vector<vector<int>> dist(a, vector<int>(b, -1));
        
        for (int i = 0; i < a; i++) {
            if (safe[i][0]) {
                q.push({i, 0});
                dist[i][0] = 1;
            }
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            
            if (c == b - 1) {
                return dist[r][c];
            }
            
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                
                if (nr >= 0 && nr < a && nc >= 0 && nc < b && safe[nr][nc] && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                } 
            }
        }
        
        return -1;
        
    }
};