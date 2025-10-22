#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> smallestSubsegment(vector<int>& arr) {
        unordered_map<int, int> freq, first, last;
        int n = arr.size();

        // Step 1: Record frequency and first/last occurrence
        for (int i = 0; i < n; i++) {
            int val = arr[i];
            freq[val]++;
            if (first.find(val) == first.end())
                first[val] = i;
            last[val] = i;
        }

        // Step 2: Find element with max frequency & smallest segment
        int maxFreq = 0;
        for (auto& it : freq)
            maxFreq = max(maxFreq, it.second);

        int bestLen = n + 1, bestStart = -1, bestEnd = -1;

        for (auto& it : freq) {
            int val = it.first;
            if (it.second == maxFreq) {
                int len = last[val] - first[val] + 1;
                if (len < bestLen || (len == bestLen && first[val] < bestStart)) {
                    bestLen = len;
                    bestStart = first[val];
                    bestEnd = last[val];
                }
            }
        }

        // Step 3: Return the subsegment
        vector<int> result;
        for (int i = bestStart; i <= bestEnd; i++)
            result.push_back(arr[i]);
        return result;
    }
};
