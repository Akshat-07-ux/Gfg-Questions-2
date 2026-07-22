#include <vector>
#include <algorithm>

class Solution {
  public:
    int minDeletions(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        std::vector<int> tails;

        for (int x : arr) {
            // Find the position of the first element in 'tails' >= x
            auto it = std::lower_bound(tails.begin(), tails.end(), x);

            if (it == tails.end()) {
                tails.push_back(x); // Extend the longest increasing sequence
            } else {
                *it = x; // Maintain the smallest tail value for sequences of this length
            }
        }

        int lisLength = tails.size();
        return n - lisLength;
    }
};