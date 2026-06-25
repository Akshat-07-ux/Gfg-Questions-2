#include <string>
#include <cctype>

class Solution {
  public:
    char decodeIt(std::string str, int k) {
        long long total_length = 0;
        int n = str.length();

        // Step 1: Calculate the total length of the decoded string
        for (int i = 0; i < n; ++i) {
            if (std::isdigit(str[i])) {
                int digit = str[i] - '0';
                total_length *= digit;
            } else {
                total_length++;
            }
        }

        // Step 2: Work backwards to find the K-th character
        for (int i = n - 1; i >= 0; --i) {
            if (std::isdigit(str[i])) {
                int digit = str[i] - '0';
                total_length /= digit; // Revert the length expansion
                k %= total_length;     // Wrap K within the smaller pattern
            } else {
                // If K lands exactly at the end of the current prefix sequence
                if (k == 0 || k == total_length) {
                    return str[i];
                }
                total_length--;
            }
        }

        return ' ';
    }
};