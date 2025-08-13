class Solution {
public:
    int maxDistinctNum(vector<int> arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;

        vector<int> costs;
        for (auto &p : freq) {
            if (p.second > 1) {
                costs.push_back(p.second - 1); // duplicates to remove
            }
        }

        int distinctCount = freq.size();
        sort(costs.begin(), costs.end());

        for (int cost : costs) {
            if (k >= cost) {
                k -= cost; // remove all duplicates for this element
            } else {
                // remove partial duplicates, element remains
                k = 0;
                break;
            }
        }

        // If we still have k > 0, we must remove whole distinct elements
        if (k > 0) {
            int removeWhole = min(k, distinctCount);
            distinctCount -= removeWhole;
        }

        return distinctCount;
    }
};
