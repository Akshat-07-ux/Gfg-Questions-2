class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        int i = 0;
        while (i < n) {
            int j = 0;

            // Step 1: Forward scan to match s2 as subsequence
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m) break;
                }
                i++;
            }

            // If s2 not fully matched, we are done
            if (j < m) break;

            // Step 2: Backward scan to minimize the window
            int end = i;
            j = m - 1;
            while (i >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                    if (j < 0) break;
                }
                i--;
            }

            int currLen = end - i + 1;
            if (currLen < minLen) {
                minLen = currLen;
                start = i;
            }

            // Move forward to search for next window
            i = i + 1;
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
