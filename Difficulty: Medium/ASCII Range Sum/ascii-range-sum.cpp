#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> asciirange(string& s) {
        unordered_map<char, pair<int, int>> positions;
        int n = s.size();

        // Step 1: Record first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (positions.find(ch) == positions.end()) {
                positions[ch] = {i, i}; // first and last initialized to current index
            } else {
                positions[ch].second = i; // update last position
            }
        }

        vector<int> result;

        // Step 2: For characters with first != last, compute ASCII sum
        for (const auto& entry : positions) {
            int first = entry.second.first;
            int last = entry.second.second;
            if (last > first + 1) { // ensure at least one character strictly between
                int sum = 0;
                for (int i = first + 1; i < last; ++i) {
                    sum += (int)s[i];
                }
                if (sum != 0)
                    result.push_back(sum);
            }
        }

        return result;
    }
};
