class Solution {
  public:
    void backtrack(vector<int>& arr, int start, vector<vector<int>>& result) {
        // Base case: If start index reaches the end, we found a permutation
        if (start == arr.size()) {
            result.push_back(arr);
            return;
        }

        for (int i = start; i < arr.size(); i++) {
            // Swap the current element with the element at the 'start' position
            swap(arr[start], arr[i]);
            
            // Recurse for the next position
            backtrack(arr, start + 1, result);
            
            // Backtrack: swap back to restore the original array state
            swap(arr[start], arr[i]);
        }
    }

    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> result;
        backtrack(arr, 0, result);
        return result;
    }
};