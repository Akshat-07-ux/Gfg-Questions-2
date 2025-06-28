#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // Sort b to enable binary search
        sort(b.begin(), b.end());
        
        vector<int> result;
        for (int x : a) {
            // upper_bound returns the first element > x, so distance gives count ≤ x
            int count = upper_bound(b.begin(), b.end(), x) - b.begin();
            result.push_back(count);
        }
        return result;
    }
};
