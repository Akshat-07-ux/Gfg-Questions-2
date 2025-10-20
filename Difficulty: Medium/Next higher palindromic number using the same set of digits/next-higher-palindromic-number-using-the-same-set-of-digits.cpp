#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string nextPalin(string N) {
        int n = N.size();
        if (n <= 3) return "-1";

        string left = N.substr(0, n / 2);
        string mid = (n % 2) ? string(1, N[n / 2]) : "";

        // Generate next permutation of the left half
        if (!next_permutation(left.begin(), left.end()))
            return "-1";

        string rev_left = left;
        reverse(rev_left.begin(), rev_left.end());

        string ans = (n % 2) ? left + mid + rev_left : left + rev_left;
        return ans;
    }
};
