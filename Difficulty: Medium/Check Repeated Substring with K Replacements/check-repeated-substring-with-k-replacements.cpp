#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool kSubstr(string &s, int k) {
        int n = s.length();
        
        // If the string length isn't perfectly divisible by k, 
        // we can't form uniform k-length repetitions.
        if (n % k != 0) return false;
        
        unordered_map<string, int> counts;
        
        // Extract each k-length block and count its occurrence
        for (int i = 0; i < n; i += k) {
            string sub = s.substr(i, k);
            counts[sub]++;
        }
        
        // If all blocks are already identical
        if (counts.size() == 1) {
            return true;
        }
        
        // If there are exactly two unique blocks, we can change one to match the other
        // ONLY if at least one of them occurs exactly once.
        if (counts.size() == 2) {
            for (auto const& [key, val] : counts) {
                if (val == 1) {
                    return true;
                }
            }
        }
        
        // If there are more than 2 unique blocks, one replacement isn't enough.
        return false;
    }
};