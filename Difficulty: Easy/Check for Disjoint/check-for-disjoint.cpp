#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool areDisjoint(vector<int> &a, vector<int> &b) {
        // Create a hash set using elements of the first array
        std::unordered_set<int> elements;
        
        for (int x : a) {
            elements.insert(x);
        }
        
        // Traverse the second array and check for existence in the set
        for (int x : b) {
            if (elements.find(x) != elements.end()) {
                // Common element found
                return false;
            }
        }
        
        // No common elements found
        return true;
    }
};