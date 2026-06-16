#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> constructList(std::vector<std::vector<int>> &queries) {
        std::vector<int> result;
        int cumulative_xor = 0;
        
        // Process queries in reverse order
        for (int i = queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0];
            int x = queries[i][1];
            
            if (type == 1) {
                // Accumulate the XOR factor
                cumulative_xor ^= x;
            } else if (type == 0) {
                // Add the element XORed with the cumulative XOR at this point
                result.push_back(x ^ cumulative_xor);
            }
        }
        
        // Include the initial element 0 which undergoes all Type-1 modifications
        result.push_back(0 ^ cumulative_xor);
        
        // Sort the final array as requested by the problem statement
        std::sort(result.begin(), result.end());
        
        return result;
    }
};