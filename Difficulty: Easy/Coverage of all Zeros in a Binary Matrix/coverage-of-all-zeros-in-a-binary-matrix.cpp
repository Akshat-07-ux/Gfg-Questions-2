#include <vector>
using namespace std;

class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int totalCoverage = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // We only calculate coverage for '0' cells
                if (mat[i][j] == 0) {
                    
                    // 1. Check UP direction
                    for (int r = i - 1; r >= 0; r--) {
                        if (mat[r][j] == 1) {
                            totalCoverage++;
                            break; // Found a 1, move to next direction
                        }
                    }
                    
                    // 2. Check DOWN direction
                    for (int r = i + 1; r < n; r++) {
                        if (mat[r][j] == 1) {
                            totalCoverage++;
                            break; 
                        }
                    }
                    
                    // 3. Check LEFT direction
                    for (int c = j - 1; c >= 0; c--) {
                        if (mat[i][c] == 1) {
                            totalCoverage++;
                            break; 
                        }
                    }
                    
                    // 4. Check RIGHT direction
                    for (int c = j + 1; c < m; c++) {
                        if (mat[i][c] == 1) {
                            totalCoverage++;
                            break; 
                        }
                    }
                    
                }
            }
        }
        
        return totalCoverage;
    }
};