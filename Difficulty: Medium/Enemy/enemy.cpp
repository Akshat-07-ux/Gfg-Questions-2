class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &enemy) {
        // If there are no enemies, the entire grid is the largest area
        if (k == 0) return n * m;

        vector<int> rows;
        vector<int> cols;

        // Boundary "enemies" to handle the space before the first 
        // and after the last actual enemy.
        rows.push_back(0);
        rows.push_back(n + 1);
        cols.push_back(0);
        cols.push_back(m + 1);

        for (int i = 0; i < k; i++) {
            rows.push_back(enemy[i][0]);
            cols.push_back(enemy[i][1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRowGap = 0;
        for (int i = 1; i < rows.size(); i++) {
            // Gap is the number of cells BETWEEN two blocked indices
            maxRowGap = max(maxRowGap, rows[i] - rows[i-1] - 1);
        }

        int maxColGap = 0;
        for (int i = 1; i < cols.size(); i++) {
            maxColGap = max(maxColGap, cols[i] - cols[i-1] - 1);
        }

        return maxRowGap * maxColGap;
    }
};