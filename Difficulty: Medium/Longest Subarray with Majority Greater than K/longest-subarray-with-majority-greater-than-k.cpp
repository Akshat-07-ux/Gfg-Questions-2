#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> diff(n);
        
        // Step 1: Convert array to +1 and -1
        for (int i = 0; i < n; ++i) {
            diff[i] = (arr[i] > k) ? 1 : -1;
        }

        // Step 2: Use prefix sum and hashmap
        unordered_map<int, int> first_occurrence;
        int prefix_sum = 0;
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            prefix_sum += diff[i];

            // Case 1: prefix sum itself is positive
            if (prefix_sum > 0) {
                max_len = i + 1;
            }

            // Case 2: find the earliest prefix_sum - 1
            else {
                if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }

            // Record the first occurrence of this prefix sum
            if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
                first_occurrence[prefix_sum] = i;
            }
        }

        return max_len;
    }
};
