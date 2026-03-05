#include <vector>
#include <set>
#include <cmath>

class Solution {
  public:
    bool closestSimilarElements(int n, vector<int> &arr, int indexDifference,
                                int valueDifference) {
        // A set to maintain the sliding window of values
        set<long long> window;
        
        for (int i = 0; i < n; i++) {
            // 1. Maintain the window size: Remove elements that are too far away
            if (i > indexDifference) {
                window.erase((long long)arr[i - indexDifference - 1]);
            }
            
            // 2. Search for a value x in the set such that:
            // arr[i] - valueDifference <= x <= arr[i] + valueDifference
            auto it = window.lower_bound((long long)arr[i] - valueDifference);
            
            // 3. Check if the found element satisfies the upper bound of the range
            if (it != window.end() && *it <= (long long)arr[i] + valueDifference) {
                return true;
            }
            
            // 4. Add current element to the window
            window.insert((long long)arr[i]);
        }
        
        return false;
    }
};