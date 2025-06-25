#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

class Solution {
  public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        unordered_map<int, int> freqCount;
        for (auto& it : freq) {
            freqCount[it.second]++;
        }

        // Case 1: All characters already have same frequency
        if (freqCount.size() == 1) return true;

        // Case 2: Exactly 2 frequencies — check if one change can balance them
        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;

            // Ensure f1 < f2 for consistent logic
            if (f1 > f2) {
                swap(f1, f2);
                swap(c1, c2);
            }

            // Case A: one char with frequency 1
            if (f1 == 1 && c1 == 1) return true;

            // Case B: higher frequency occurs only once and is f1+1
            if (f2 == f1 + 1 && c2 == 1) return true;
        }

        return false;
    }
};
