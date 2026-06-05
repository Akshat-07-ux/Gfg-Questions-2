#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Initialize both current tracking and global minimum with the first element
        int min_sum = a[0];
        int current_sum = a[0];
        
        // Iterate through the rest of the array
        for (size_t i = 1; i < a.size(); i++) {
            // Decide to either continue the existing subarray or start a new one
            current_sum = min(a[i], current_sum + a[i]);
            
            // Update the global minimum sum found so far
            min_sum = min(min_sum, current_sum);
        }
        
        return min_sum;
    }
};