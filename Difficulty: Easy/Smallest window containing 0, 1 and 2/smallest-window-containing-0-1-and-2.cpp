class Solution {
  public:
    int smallestSubstring(string s) {
        int last0 = -1, last1 = -1, last2 = -1;
        int minLen = 1e9; // Initialize with a large value
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // Update the last seen index for the current character
            if (s[i] == '0') last0 = i;
            else if (s[i] == '1') last1 = i;
            else if (s[i] == '2') last2 = i;

            // If we have seen all three characters at least once
            if (last0 != -1 && last1 != -1 && last2 != -1) {
                // The current valid substring ends at index i
                // and starts at the minimum of the three indices
                int currentMinIdx = min({last0, last1, last2});
                int currentLen = i - currentMinIdx + 1;
                
                minLen = min(minLen, currentLen);
            }
        }

        // If minLen was never updated, no valid substring exists
        return (minLen == 1e9) ? -1 : minLen;
    }
};