#include <vector>
#include <algorithm>

class Solution {
  public:
    std::vector<int> RopeCutting(std::vector<int>& arr) {
        std::vector<int> result;
        int n = arr.size();
        
        // Step 1: Sort the array - O(n log n) time, O(1) auxiliary space
        std::sort(arr.begin(), arr.end());
        
        // Step 2: Traverse the sorted array to find cut points
        for (int i = 1; i < n; i++) {
            // A cut happens when we transition to a strictly larger rope length
            if (arr[i] > arr[i - 1]) {
                // The number of remaining ropes is the elements from index i to n-1
                result.push_back(n - i);
            }
        }
        
        return result;
    }
};