#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
  public:
    // Function to find the difference between the maximum and minimum frequency of elements.
    int findDiff(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        // If only one unique element exists, return 0
        if (freq.size() == 1) return 0;

        int minFreq = INT_MAX;
        int maxFreq = INT_MIN;

        for (auto& it : freq) {
            int f = it.second;
            minFreq = min(minFreq, f);
            maxFreq = max(maxFreq, f);
        }

        return maxFreq - minFreq;
    }
};
