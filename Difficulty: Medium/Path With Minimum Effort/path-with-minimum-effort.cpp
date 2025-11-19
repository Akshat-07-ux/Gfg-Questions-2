class Solution {
  public:
    int n, m;
    vector<vector<int>> mat;

    bool canReach(int limit) {
        // BFS/DFS to check reachability under the allowed diff
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({0, 0});
        vis[0][0] = true;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1) return true;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    if (abs(mat[nx][ny] - mat[x][y]) <= limit) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }

    int minCostPath(vector<vector<int>>& matrix) {
        mat = matrix;
        n = mat.size();
        m = mat[0].size();

        int low = 0, high = 1e6, ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canReach(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
