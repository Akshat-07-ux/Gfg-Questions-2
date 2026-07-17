#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int max_non_overlapping(vector<vector<int>>& ranges) {
        if (ranges.empty()) return 0;
        
        // Sort the intervals primarily by their end times (ranges[i][1])
        sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 1; // Pick the first bundle (the one ending earliest)
        int last_end_time = ranges[0][1];
        
        for (size_t i = 1; i < ranges.size(); i++) {
            // If the current bundle starts after or when the last one ends
            if (ranges[i][0] >= last_end_time) {
                count++;
                last_end_time = ranges[i][1]; // Update to the current bundle's end time
            }
        }
        
        return count;
    }
};