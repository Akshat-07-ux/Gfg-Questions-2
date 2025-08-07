#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int minDifference(vector<string> &arr) {
        vector<int> timesInSeconds;

        // Convert each HH:MM:SS to seconds
        for (const string &time : arr) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            int seconds = stoi(time.substr(6, 2));
            int totalSeconds = hours * 3600 + minutes * 60 + seconds;
            timesInSeconds.push_back(totalSeconds);
        }

        sort(timesInSeconds.begin(), timesInSeconds.end());

        int minDiff = INT_MAX;

        // Compare adjacent times
        for (int i = 1; i < timesInSeconds.size(); ++i) {
            minDiff = min(minDiff, timesInSeconds[i] - timesInSeconds[i - 1]);
        }

        // Wrap-around: from last to first (24*3600 seconds in a day)
        int wrapAroundDiff = 86400 - timesInSeconds.back() + timesInSeconds.front();
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
    }
};
