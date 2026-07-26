#include <vector>
#include <algorithm>

class Solution {
  public:
    std::vector<std::vector<int>> levelSort(std::vector<int>& arr) {
        std::vector<std::vector<int>> result;
        int n = arr.size();
        
        int start = 0;
        int count = 1; // Number of elements at the current level (2^k)

        while (start < n) {
            // Determine the end boundary for the current level
            int end = std::min(start + count, n);
            
            // Extract the elements for this level
            std::vector<int> level(arr.begin() + start, arr.begin() + end);
            
            // Sort the level elements in ascending order
            std::sort(level.begin(), level.end());
            
            // Append to the result
            result.push_back(level);
            
            // Move to the next level
            start = end;
            count *= 2; // Next level has twice as many potential nodes
        }

        return result;
    }
};