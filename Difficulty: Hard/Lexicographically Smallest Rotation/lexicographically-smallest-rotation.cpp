#include <string>
#include <vector>
#include <algorithm>

class Solution {
  public:
    string lexiString(string &s) {
        int n = s.length();
        string S = s + s; // Concatenate string to handle circular shifts
        vector<int> f(2 * n, -1); // Failure function array
        int k = 0; // Starting index of the lexicographically smallest rotation

        for (int j = 1; j < 2 * n; ++j) {
            char sj = S[j];
            int i = f[j - k - 1];

            while (i != -1 && sj != S[k + i + 1]) {
                if (sj < S[k + i + 1]) {
                    k = j - i - 1;
                }
                i = f[i];
            }

            if (sj != S[k + i + 1]) {
                if (sj < S[k]) {
                    k = j;
                }
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }

        return S.substr(k, n);
    }
};