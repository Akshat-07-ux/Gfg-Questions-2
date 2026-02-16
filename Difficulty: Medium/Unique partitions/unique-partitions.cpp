class Solution {
  public:
    void solve(int target, int max_val, vector<int>& current, vector<vector<int>>& result) {
        // Base case: target sum achieved
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Try all numbers from max_val down to 1
        for (int i = max_val; i >= 1; i--) {
            if (target >= i) {
                current.push_back(i);
                // The next number chosen cannot be greater than 'i' 
                // to maintain decreasing order
                solve(target - i, i, current, result);
                current.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> result;
        vector<int> current;
        solve(n, n, current, result);
        return result;
    }
};