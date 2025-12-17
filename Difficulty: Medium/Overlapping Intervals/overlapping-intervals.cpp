class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // If no intervals, return empty
        if (arr.empty()) return {};

        // Step 1: Sort intervals by starting time
        sort(arr.begin(), arr.end());

        vector<vector<int>> merged;
        merged.push_back(arr[0]);

        // Step 2: Merge overlapping intervals
        for (int i = 1; i < arr.size(); i++) {
            // If current interval overlaps with the last merged interval
            if (arr[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], arr[i][1]);
            } else {
                // No overlap, push new interval
                merged.push_back(arr[i]);
            }
        }

        return merged;
    }
};
