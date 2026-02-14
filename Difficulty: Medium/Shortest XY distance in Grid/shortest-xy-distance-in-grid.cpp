#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // dist[i][j] will store the minimum distance from any 'X' to (i, j)
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        queue<pair<int, int>> q;

        // Step 1: Push all 'X' coordinates into the queue as starting points
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'X') {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Direction vectors for moving Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            // If we find a 'Y', it must be the shortest distance because of BFS properties
            if (grid[r][c] == 'Y') {
                return dist[r][c];
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                // Check bounds and if the cell has been visited
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1; // Should not reach here based on constraints
    }
};