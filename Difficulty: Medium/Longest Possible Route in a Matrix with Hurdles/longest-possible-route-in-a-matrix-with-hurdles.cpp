class Solution {
public:
    int n, m;
    int ans = -1;
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void dfs(vector<vector<int>>& mat, int x, int y, int xd, int yd, int dist) {
        // Destination reached
        if (x == xd && y == yd) {
            ans = max(ans, dist);
            return;
        }
        
        // Mark visited
        mat[x][y] = 0;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                dfs(mat, nx, ny, xd, yd, dist + 1);
            }
        }
        
        // Backtrack
        mat[x][y] = 1;
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
        n = matrix.size();
        m = matrix[0].size();
        
        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0)
            return -1;
        
        dfs(matrix, xs, ys, xd, yd, 0);
        return ans;
    }
};
