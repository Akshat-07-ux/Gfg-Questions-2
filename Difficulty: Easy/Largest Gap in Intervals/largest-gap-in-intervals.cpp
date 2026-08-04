#include <vector>
#include <algorithm>

class Solution {
  public:
    int maximumGap(std::vector<int>& start, std::vector<int>& end) {
        int n = start.size();
        if (n <= 1) return 0;

        // Step 1: Combine start and end into pairs
        std::vector<std::pair<int, int>> intervals(n);
        for (int i = 0; i < n; ++i) {
            intervals[i] = {start[i], end[i]};
        }

        // Step 2: Sort intervals by start time
        std::sort(intervals.begin(), intervals.end());

        int max_gap = 0;
        int current_end = intervals[0].second;

        // Step 3: Iterate through sorted intervals and compute gaps
        for (int i = 1; i < n; ++i) {
            int next_start = intervals[i].first;
            int next_end = intervals[i].second;

            if (next_start > current_end) {
                // Gap found: update maximum gap
                max_gap = std::max(max_gap, next_start - current_end);
                current_end = next_end;
            } else {
                // Overlapping or touching intervals: extend current end
                current_end = std::max(current_end, next_end);
            }
        }

        return max_gap;
    }
};