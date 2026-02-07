class Solution {
  public:
    vector<pair<int, int>> missingIntervals(vector<int> &arr, int l, int r) {
        vector<pair<int, int>> result;
        int current = l;

        for (int i = 0; i < arr.size(); i++) {
            // Only care about numbers within or ahead of our current search range
            if (arr[i] < current) continue;

            // If there's a gap between current expected and arr[i]
            if (arr[i] > current) {
                result.push_back({current, arr[i] - 1});
            }

            // Update current to the next number after arr[i]
            // Using a check to prevent overflow if arr[i] is INT_MAX
            if (arr[i] == r) {
                current = r + 1;
                break; 
            }
            current = arr[i] + 1;
        }

        // Final check: is there a gap between the last element and r?
        if (current <= r) {
            result.push_back({current, r});
        }

        // If no intervals were found
        if (result.empty()) {
            return {{-1, -1}};
        }

        return result;
    }
};