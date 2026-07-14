#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &arr, int target) {
        unordered_set<int> seen;
        
        for (int num : arr) {
            int complement = target - num;
            
            // If the complement is already in the set, we found our pair
            if (seen.count(complement)) {
                return {complement, num};
            }
            
            // Otherwise, store the current number in the set
            seen.insert(num);
        }
        
        // Return an empty array if no such pair exists
        return {};
    }
};