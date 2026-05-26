#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();
        
        // Count total number of 0s in the entire array
        int total_zeros = 0;
        for (int num : arr) {
            if (num == 0) {
                total_zeros++;
            }
        }
        
        // If the array is partitioned at the very beginning (index 0),
        // all 0s must be toggled to 1s.
        int min_toggles = total_zeros;
        
        int left_ones = 0;
        int right_zeros = total_zeros;
        
        // Iterate through the array to check every possible partition point
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                left_ones++;
            } else {
                right_zeros--;
            }
            
            // Toggles needed if partition is after index i:
            // left_ones (to become 0) + right_zeros (to become 1)
            min_toggles = min(min_toggles, left_ones + right_zeros);
        }
        
        return min_toggles;
    }
};