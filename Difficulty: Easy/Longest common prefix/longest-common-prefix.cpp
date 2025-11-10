#include <string>
using namespace std;

class Solution {
  public:
    int longestCommonPrefix(string str1, string str2) {
        int n = str1.size();
        int maxLen = 0;

        // Try every prefix of str1
        for (int len = 1; len <= n; len++) {
            string prefix = str1.substr(0, len);
            // Check if this prefix exists in str2
            if (str2.find(prefix) != string::npos) {
                maxLen = len;
            } else {
                break; // further prefixes won't match if current one doesn't
            }
        }

        return maxLen;
    }
};
