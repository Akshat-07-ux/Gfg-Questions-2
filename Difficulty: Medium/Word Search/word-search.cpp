class Solution {
public:
    bool backtrack(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        // Base Case: If we've matched all characters in the word
        if (index == word.length()) {
            return true;
        }

        // Boundary checks and character matching
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) {
            return false;
        }

        // Mark the current cell as visited
        char temp = mat[i][j];
        mat[i][j] = '#'; 

        // Explore all 4 adjacent directions
        bool found = backtrack(mat, word, i + 1, j, index + 1) ||
                     backtrack(mat, word, i - 1, j, index + 1) ||
                     backtrack(mat, word, i, j + 1, index + 1) ||
                     backtrack(mat, word, i, j - 1, index + 1);

        // Backtrack: Restore the original character
        mat[i][j] = temp;

        return found;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the first character matches, start the recursion
                if (mat[i][j] == word[0]) {
                    if (backtrack(mat, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};