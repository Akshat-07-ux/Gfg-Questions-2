class Solution {
  public:
    int maxSubstring(string &s) {
        int max_so_far = -1;
        int current_sum = 0;
        bool has_zero = false;

        for (char c : s) {
            // Step 1: Map 0 -> 1 and 1 -> -1
            int val = (c == '0') ? 1 : -1;
            
            if (c == '0') has_zero = true;

            // Step 2: Standard Kadane's Algorithm logic
            current_sum += val;

            if (current_sum > max_so_far) {
                max_so_far = current_sum;
            }

            // If current_sum drops below 0, reset it. 
            // However, we only reset if it won't interfere 
            // with finding the max in an all-1s string.
            if (current_sum < 0) {
                current_sum = 0;
            }
        }

        // If no '0' was ever found, the answer is -1 (as per constraints)
        return has_zero ? max_so_far : -1;
    }
};