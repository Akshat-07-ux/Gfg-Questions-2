class Solution {
public:
    // All 8 possible knight moves
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool isValid(int x, int y, int n, vector<vector<int>>& board) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }
    
    bool solveKT(int x, int y, int moveCount, vector<vector<int>>& board, int n) {
        if (moveCount == n * n) return true; // All cells visited
        
        for (int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (isValid(nextX, nextY, n, board)) {
                board[nextX][nextY] = moveCount;
                if (solveKT(nextX, nextY, moveCount + 1, board, n))
                    return true;
                // backtrack
                board[nextX][nextY] = -1;
            }
        }
        return false;
    }
    
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        
        board[0][0] = 0; // starting point
        
        if (!solveKT(0, 0, 1, board, n))
            return {}; // no solution exists
        
        return board;
    }
};
