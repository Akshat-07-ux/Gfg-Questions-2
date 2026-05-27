class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int n = s.length();
        int covered_until = -1; // Tracks the rightmost index covered so far

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int left_bound = max(0, i - x);
                int right_bound = i + x;

                // If the start of the current router's range leaves an uncovered gap
                if (left_bound > covered_until + 1) {
                    return false;
                }

                // Update the maximum covered room index
                covered_until = max(covered_until, right_bound);
            }
        }

        // Check if the coverage extends to or past the final room
        return covered_until >= n - 1;
    }
};