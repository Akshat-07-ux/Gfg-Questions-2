#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void findCombinations(int index, int target, vector<int>& arr, vector<int>& current, vector<vector<int>>& result) {
        // Base Case: If target is met, record the combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            // Early Pruning: If the element is greater than the target, no need to check further
            if (arr[i] > target) break;

            // Duplicate Elimination: Skip elements that are identical to the previous element 
            // in the same recursive step
            if (i > index && arr[i] == arr[i - 1]) continue;

            // Include the element
            current.push_back(arr[i]);
            
            // Move to the next element (i + 1 ensures each element is used at most once)
            findCombinations(i + 1, target - arr[i], arr, current, result);
            
            // Backtrack: Remove the element to explore other combinations
            current.pop_back();
        }
    }

public:
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Step 1: Sort the array to handle duplicates and enable pruning
        sort(arr.begin(), arr.end());
        
        // Step 2: Start backtracking
        findCombinations(0, target, arr, current, result);
        
        return result;
    }
};