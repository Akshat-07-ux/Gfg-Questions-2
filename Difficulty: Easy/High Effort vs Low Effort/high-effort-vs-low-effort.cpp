#include <vector>
#include <algorithm>

class Solution {
  public:
    int maxTask(std::vector<int>& h, std::vector<int>& l) {
        int n = h.size();
        if (n == 0) return 0;
        if (n == 1) return std::max(h[0], l[0]);

        // task_2_back: max tasks up to day i-2
        // task_1_back: max tasks up to day i-1
        int task_2_back = 0; 
        int task_1_back = std::max(h[0], l[0]); // Best choice for Day 0

        for (int i = 1; i < n; ++i) {
            // Option 1: Do a high-effort task on day i (requires day i-1 to be skipped/rest)
            int current_high = task_2_back + h[i];

            // Option 2: Do a low-effort task on day i (no restrictions on day i-1)
            int current_low = task_1_back + l[i];

            // Maximum tasks achieved ending on day i
            int current_max = std::max(current_high, current_low);

            // Shift DP states for the next iteration
            task_2_back = task_1_back;
            task_1_back = current_max;
        }

        return task_1_back;
    }
};