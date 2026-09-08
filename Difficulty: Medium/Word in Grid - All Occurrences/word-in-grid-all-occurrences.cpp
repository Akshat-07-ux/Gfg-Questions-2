#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();

        // 8 possible directions: {row_offset, col_offset}
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        set<vector<int>> unique_coords;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if the starting cell matches the first character of the word
                if (mat[i][j] == word[0]) {
                    // Explore all 8 directions from the current cell
                    for (int dir = 0; dir < 8; dir++) {
                        int k, curr_r = i, curr_c = j;

                        for (k = 0; k < len; k++) {
                            // Verify boundaries and character match
                            if (curr_r >= 0 && curr_r < n && curr_c >= 0 && curr_c < m && mat[curr_r][curr_c] == word[k]) {
                                curr_r += dr[dir];
                                curr_c += dc[dir];
                            } else {
                                break;
                            }
                        }

                        // If the complete word matches in this direction
                        if (k == len) {
                            unique_coords.insert({i, j});
                            break; // No need to check other directions for this starting point once found
                        }
                    }
                }
            }
        }

        // Convert the set to a vector which naturally maintains lexicographical order
        return vector<vector<int>>(unique_coords.begin(), unique_coords.end());
    }
};