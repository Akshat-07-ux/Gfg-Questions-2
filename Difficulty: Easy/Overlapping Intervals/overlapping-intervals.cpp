#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        int n = intervals.size();
        if (n <= 1) return false;

        // Step 1: Sort the intervals based on start times
        sort(intervals.begin(), intervals.end());

        // Step 2: Iterate through and check for adjacent overlaps
        for (int i = 1; i < n; i++) {
            // If the start of current interval is <= end of previous interval
            if (intervals[i][0] <= intervals[i - 1][1]) {
                return true;
            }
        }

        return false;
    }
};