#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int fun(string s, int k, int n, char c) {
        long long len = s.size();

        // Count occurrences of c in one copy of s
        long long countInS = 0;
        for (char ch : s) {
            if (ch == c) countInS++;
        }

        // Total length of the repeated string
        long long totalLength = len * 1LL * k;

        // If n is greater than total length, adjust (though per constraints, n <= |s| * k)
        n = min((long long)n, totalLength);

        // Number of complete repetitions within first n chars
        long long fullRepeats = n / len;

        // Remaining characters from the next repetition
        long long remainder = n % len;

        // Count occurrences in the remaining part
        long long countInRemainder = 0;
        for (int i = 0; i < remainder; i++) {
            if (s[i] == c) countInRemainder++;
        }

        // Total occurrences
        long long total = fullRepeats * countInS + countInRemainder;

        return (int)total;
    }
};

