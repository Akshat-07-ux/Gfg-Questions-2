class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        if (n == 0) return {};
        
        vector<int> result;
        // There are (2*n - 1) anti-diagonals
        int numDiagonals = 2 * n - 1;
        
        for (int s = 0; s < numDiagonals; ++s) {
            // For a sum 's', the smallest possible i such that j (s-i) is valid (j < n)
            int i = max(0, s - (n - 1));
            
            // Traverse from top-right towards bottom-left for this specific diagonal
            while (i < n && (s - i) >= 0) {
                int j = s - i;
                result.push_back(mat[i][j]);
                i++;
            }
        }
        
        return result;
    }
};