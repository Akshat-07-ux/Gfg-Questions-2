class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int left  = max(0, i - arr[i]);
                int right = min(n - 1, i + arr[i]);
                intervals.push_back({left, right});
            }
        }

        // Sort by starting point
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int idx = 0;
        int coveredTill = 0;

        // Greedy interval covering
        while (coveredTill < n) {
            int farthest = coveredTill;

            while (idx < intervals.size() && intervals[idx].first <= coveredTill) {
                farthest = max(farthest, intervals[idx].second + 1);
                idx++;
            }

            // If no progress is made, coverage fails
            if (farthest == coveredTill)
                return -1;

            count++;
            coveredTill = farthest;
        }

        return count;
    }
};
