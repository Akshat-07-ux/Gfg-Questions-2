#include <unordered_map>
#include <unordered_set>

class Solution {
  public:
    bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each element
        for (int i = 0; i < n; ++i) {
            freq[arr[i]]++;
        }

        unordered_set<int> seenFrequencies;

        // Step 2: Check if all frequencies are unique
        for (auto &entry : freq) {
            int f = entry.second;
            if (seenFrequencies.count(f)) {
                return false; // Frequency already seen, not unique
            }
            seenFrequencies.insert(f);
        }

        return true;
    }
};
