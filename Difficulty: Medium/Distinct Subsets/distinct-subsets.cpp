#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    void backtrack(int index, vector<int>& arr, vector<int>& current, vector<vector<int>>& result) {
        // Add the currently formed subset to the result
        result.push_back(current);
        
        for (int i = index; i < arr.size(); i++) {
            // If the current element is a duplicate of the previous element 
            // and we didn't pick the previous element in this step, skip it.
            if (i > index && arr[i] == arr[i - 1]) {
                continue;
            }
            
            // Include the element
            current.push_back(arr[i]);
            
            // Move to the next element
            backtrack(i + 1, arr, current, result);
            
            // Backtrack: remove the element to try other combinations
            current.pop_back();
        }
    }

  public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the array to handle duplicates efficiently
        sort(arr.begin(), arr.end());
        
        // Start backtracking from index 0
        backtrack(0, arr, current, result);
        
        return result;
    }
};