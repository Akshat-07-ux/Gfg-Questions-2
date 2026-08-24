#include <string>

class Solution {
  public:
    std::string newIPAdd(std::string &s) {
        std::string result = "";
        int n = s.length();
        int i = 0;

        while (i < n) {
            int j = i;
            // Find the end of the current segment
            while (j < n && s[j] != '.') {
                j++;
            }

            // Skip leading zeros in the current segment [i, j)
            int k = i;
            while (k < j && s[k] == '0') {
                k++;
            }

            // If the segment was entirely zeros, append a single '0'
            if (k == j) {
                result += '0';
            } else {
                // Otherwise, append digits starting from the first non-zero digit
                while (k < j) {
                    result += s[k];
                    k++;
                }
            }

            // Append '.' if we haven't reached the end of the string
            if (j < n) {
                result += '.';
            }

            // Move to the next segment
            i = j + 1;
        }

        return result;
    }
};