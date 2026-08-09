#include <string>

using namespace std;

class Solution {
  public:
    int isSame(string &s) {
        int n = s.length();
        int i = n - 1;

        // Traverse backwards to find the start of the trailing number
        while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
            i--;
        }

        // If there are no trailing digits at all
        if (i == n - 1) return 0;

        // Extract the trailing number manually to avoid overflow/large numbers
        long long num = 0;
        int num_len = n - (i + 1);
        int text_len = i + 1;

        for (int j = i + 1; j < n; ++j) {
            num = num * 10 + (s[j] - '0');
            // If the trailing number exceeds the total remaining prefix length,
            // it can never be equal to text_len
            if (num > text_len) return 0;
        }

        return (num == text_len) ? 1 : 0;
    }
};