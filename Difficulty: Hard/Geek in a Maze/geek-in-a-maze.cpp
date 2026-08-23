#include <vector>
#include <deque>

using namespace std;

class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Base cases
        if (r < 0 || r >= n || c < 0 || c >= m || mat[r][c] == '#') {
            return 0;
        }

        // min_u[i][j] stores the minimum up moves to reach (i, j)
        // min_d[i][j] stores the minimum down moves to reach (i, j)
        vector<vector<int>> min_u(n, vector<int>(m, 1e9));
        vector<vector<int>> min_d(n, vector<int>(m, 1e9));

        // Structure for deque elements: {row, col, up_moves, down_moves}
        struct Node {
            int row, col, up, down;
        };

        deque<Node> dq;

        min_u[r][c] = 0;
        min_d[r][c] = 0;
        dq.push_back({r, c, 0, 0});

        int visitedCount = 0;

        // Track visited state to avoid double counting
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Directions: Up (0), Down (1), Left (2), Right (3)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            Node curr = dq.front();
            dq.pop_front();

            int cr = curr.row;
            int cc = curr.col;

            if (!visited[cr][cc]) {
                visited[cr][cc] = true;
                visitedCount++;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.') {
                    int next_u = curr.up + (i == 0 ? 1 : 0);
                    int next_d = curr.down + (i == 1 ? 1 : 0);

                    // Check budget limits
                    if (next_u <= u && next_d <= d) {
                        // Relaxation condition
                        if (next_u < min_u[nr][nc] || next_d < min_d[nr][nc]) {
                            // Update distance matrices
                            if (next_u < min_u[nr][nc]) min_u[nr][nc] = next_u;
                            if (next_d < min_d[nr][nc]) min_d[nr][nc] = next_d;

                            // 0-cost move (Left/Right) goes to the front of deque
                            if (i >= 2) {
                                dq.push_front({nr, nc, next_u, next_d});
                            } 
                            // 1-cost move (Up/Down) goes to the back of deque
                            else {
                                dq.push_back({nr, nc, next_u, next_d});
                            }
                        }
                    }
                }
            }
        }

        return visitedCount;
    }
};