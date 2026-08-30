#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
  public:
    std::vector<int> getMarks(std::vector<int> &l, std::vector<int> &r, std::vector<int> &rank) {
        int n = l.size();
        std::vector<long long> pref(n);

        // Compute prefix sums of total elements covered by intervals up to index i
        long long current_total = 0;
        for (int i = 0; i < n; ++i) {
            current_total += (long long)(r[i] - l[i] + 1);
            pref[i] = current_total;
        }

        std::vector<int> result;
        result.reserve(rank.size());

        // Process each rank query using binary search
        for (int k : rank) {
            // Find the first interval whose cumulative count is >= k
            auto it = std::lower_bound(pref.begin(), pref.end(), k);
            int idx = std::distance(pref.begin(), it);

            // Calculate how many elements were present before the current interval
            long long prev_count = (idx > 0) ? pref[idx - 1] : 0;

            // Offset within the current interval
            long long offset = k - prev_count - 1;

            result.push_back(l[idx] + offset);
        }

        return result;
    }
};