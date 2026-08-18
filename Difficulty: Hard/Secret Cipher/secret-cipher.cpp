#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string compress(string &s) {
        int n = s.length();

        // Compute LCP array using Z-algorithm to quickly check prefix matches
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        string result = "";
        int i = n - 1;

        // Traverse backwards from the end of the string
        while (i >= 0) {
            // Check if s[0...len-1] matches s[len...2*len-1]
            // Length of repeat candidate must be even and fit in current index i
            if ((i + 1) % 2 == 0) {
                int half = (i + 1) / 2;
                // z[half] gives the length of match of prefix s[0...] with s[half...]
                if (z[half] >= half) {
                    result += '*';
                    i = half - 1; // Move pointer to before the repeated section
                    continue;
                }
            }

            result += s[i];
            i--;
        }

        // Reverse to get the string from left to right
        reverse(result.begin(), result.end());
        return result;
    }
};