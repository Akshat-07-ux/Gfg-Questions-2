#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        if (mat.empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        // 1. Initial Scan: Find all rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // If there are no fresh oranges to rot, time taken is 0
        if (freshCount == 0) return 0;
        
        int time = 0;
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        // 2. BFS: Spread the rot layer by layer
        while (!q.empty()) {
            int size = q.size();
            bool rottedAnyInThisStep = false;
            
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int nrow = curr.first + dRow[d];
                    int ncol = curr.second + dCol[d];
                    
                    // If neighbor is within bounds and is a fresh orange
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1) {
                        mat[nrow][ncol] = 2; // Make it rotten
                        q.push({nrow, ncol});
                        freshCount--;
                        rottedAnyInThisStep = true;
                    }
                }
            }
            // Increment time only if at least one fresh orange was infected in this step
            if (rottedAnyInThisStep) time++;
        }
        
        // 3. Final Check: If fresh oranges remain, return -1
        return (freshCount == 0) ? time : -1;
    }
};