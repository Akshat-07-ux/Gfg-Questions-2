#include <vector>
#include <algorithm>

class Solution {
  public:
    int findSmallest(std::vector<int> &arr) {
        // Step 1: Sort the array in ascending order
        std::sort(arr.begin(), arr.end());
        
        // Step 2: Initialize the smallest positive integer we want to find
        int res = 1;
        
        // Step 3: Traverse the sorted array
        for (int i = 0; i < arr.size(); i++) {
            // If the current element is greater than 'res', 
            // then 'res' cannot be formed.
            if (arr[i] > res) {
                break;
            }
            
            // Otherwise, we can represent all numbers up to res + arr[i] - 1
            res += arr[i];
        }
        
        return res;
    }
};