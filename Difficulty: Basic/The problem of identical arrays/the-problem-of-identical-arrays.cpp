#include <vector>
#include <unordered_map>

class Solution {
  public:
    bool isIdentical(std::vector<int> &a, std::vector<int> &b) {
        // Since the constraint says a.size() == b.size(), 
        // we don't strictly need a size check, but it's good practice.
        if (a.size() != b.size()) return false;

        std::unordered_map<int, int> counts;

        // Count occurrences in array 'a'
        for (int num : a) {
            counts[num]++;
        }

        // Subtract occurrences using array 'b'
        for (int num : b) {
            // If the element doesn't exist in 'a', or we've seen it 
            // more times in 'b' than 'a', they aren't identical.
            if (counts.find(num) == counts.end() || counts[num] == 0) {
                return false;
            }
            counts[num]--;
        }

        // If we've reached here, all counts are zero, meaning they match.
        return true;
    }
};