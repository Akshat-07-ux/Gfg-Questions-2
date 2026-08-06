#include <vector>
#include <algorithm>

class Solution {
  public:
    int countMinOperations(std::vector<int>& arr) {
        int total_increments = 0;
        int max_val = 0;

        for (int num : arr) {
            // Count set bits (number of +1 operations for this element)
            total_increments += __builtin_popcount(num);
            
            // Keep track of the maximum value to determine maximum doublings
            if (num > max_val) {
                max_val = num;
            }
        }

        // If the maximum value is 0, no operations are required
        if (max_val == 0) {
            return 0;
        }

        // The number of doubling operations needed is floor(log2(max_val))
        int max_doubles = 31 - __builtin_clz(max_val);

        return total_increments + max_doubles;
    }
};