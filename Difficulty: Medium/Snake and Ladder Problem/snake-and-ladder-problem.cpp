#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int target = n * n;

        // Base case: already at the end cell
        if (target == 1) return 0;

        // board[i] holds the destination cell after considering snakes/ladders at cell i
        vector<int> board(target + 1);
        for (int i = 1; i <= target; ++i) {
            board[i] = i;
        }

        // Apply ladders
        for (int i = 0; i < lad.size(); i += 2) {
            board[lad[i]] = lad[i + 1];
        }

        // Apply snakes
        for (int i = 0; i < sn.size(); i += 2) {
            board[sn[i]] = sn[i + 1];
        }

        // BFS setup
        queue<pair<int, int>> q; // {current_cell, current_throws}
        vector<bool> visited(target + 1, false);

        // Start from cell 1
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, throws] = q.front();
            q.pop();

            // Try all possible dice throws from 1 to 6
            for (int dice = 1; dice <= 6; ++dice) {
                int next_cell = curr + dice;

                if (next_cell <= target) {
                    int dest = board[next_cell];

                    // Check if we reached the final cell
                    if (dest == target) {
                        return throws + 1;
                    }

                    // If not visited, add to queue
                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.push({dest, throws + 1});
                    }
                }
            }
        }

        return -1; // If cell n*n cannot be reached
    }
};