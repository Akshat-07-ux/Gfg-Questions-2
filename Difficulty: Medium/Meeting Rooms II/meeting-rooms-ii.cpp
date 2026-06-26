#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // Sort start and end times independently
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int startPtr = 0, endPtr = 0;
        int activeRooms = 0;
        int maxRooms = 0;
        int n = start.size();
        
        // Process all meetings chronologically
        while (startPtr < n) {
            // If a new meeting starts before the oldest active meeting ends
            if (start[startPtr] < end[endPtr]) {
                activeRooms++;
                startPtr++;
            } 
            // If a meeting ends before or exactly at the start of the next meeting
            else {
                activeRooms--;
                endPtr++;
            }
            
            // Record the peak number of rooms required
            maxRooms = max(maxRooms, activeRooms);
        }
        
        return maxRooms;
    }
};