class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> events; // position -> net change in count
        
        // Create events for each interval
        for (auto& interval : intervals) {
            events[interval[0]]++;        // Start of interval (inclusive)
            events[interval[1] + 1]--;    // End of interval (exclusive)
        }
        
        int maxPowerful = -1;
        int currentCount = 0;
        int prevPos = -1;
        
        // Process events in sorted order
        for (auto& event : events) {
            int pos = event.first;
            int delta = event.second;
            
            // Check the segment before this position
            if (prevPos != -1 && currentCount >= k) {
                // Segment from prevPos to pos-1 has currentCount intervals
                maxPowerful = max(maxPowerful, pos - 1);
            }
            
            // Update count for next segment
            currentCount += delta;
            prevPos = pos;
        }
        
        return maxPowerful;
    }
};