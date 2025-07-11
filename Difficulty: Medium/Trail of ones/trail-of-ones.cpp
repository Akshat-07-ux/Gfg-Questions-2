#include <cmath> // for pow

class Solution {
  public:
    int countConsec(int n) {
        // Base cases
        if (n < 2) return 0;

        int a[n+1], b[n+1];
        a[1] = 1; // string "0"
        b[1] = 1; // string "1"

        for (int i = 2; i <= n; i++) {
            a[i] = a[i-1] + b[i-1];
            b[i] = a[i-1];
        }

        int count_no_consec = a[n] + b[n];
        int total = 1 << n; // 2^n

        return total - count_no_consec;
    }
};
