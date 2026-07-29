#include <vector>
#include <algorithm>

class Solution {
  public:
    int minSubsets(std::vector<int>& arr) {
        if (arr.empty()) return 0;
        
        // Step 1: Sort the array in ascending order
        std::sort(arr.begin(), arr.end());
        
        int count = 1; // Start with at least 1 subset for a non-empty array
        
        // Step 2: Iterate through the sorted array and count sequence breaks
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1] + 1) {
                count++;
            }
        }
        
        return count;
    }
};