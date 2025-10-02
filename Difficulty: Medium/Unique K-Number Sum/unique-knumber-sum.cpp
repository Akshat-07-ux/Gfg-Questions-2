class Solution {
  public:
    vector<vector<int>> ans;
    
    void backtrack(int start, int k, int n, vector<int> &path) {
        // Base case: if we have chosen k numbers
        if (path.size() == k) {
            if (n == 0) ans.push_back(path);
            return;
        }
        
        // Try numbers from 'start' to 9
        for (int i = start; i <= 9; i++) {
            if (i > n) break; // pruning: no need to go further
            path.push_back(i);
            backtrack(i + 1, k, n - i, path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        ans.clear();
        vector<int> path;
        backtrack(1, k, n, path);
        return ans;
    }
};
