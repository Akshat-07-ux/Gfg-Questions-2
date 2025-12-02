class Solution {
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int dir = 0;   // 0=right, 1=down, 2=left, 3=up

        while (i >= 0 && i < n && j >= 0 && j < m) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                dir = (dir + 1) % 4;
            }

            // Move according to direction
            if (dir == 0) j++;       // right  
            else if (dir == 1) i++;  // down
            else if (dir == 2) j--;  // left
            else i--;                // up
        }

        // Adjust back to the last valid position
        if (dir == 0) j--;
        else if (dir == 1) i--;
        else if (dir == 2) j++;
        else i++;

        return {i, j};
    }
};
