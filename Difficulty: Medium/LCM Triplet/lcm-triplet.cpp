#include <algorithm>
using namespace std;

class Solution {
  public:
    long long lcm(long long a, long long b) {
        return (a * b) / __gcd(a, b);
    }

    long long lcm3(long long a, long long b, long long c) {
        return lcm(lcm(a, b), c);
    }

    int lcmTriplets(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;

        long long res = 0;

        if (n % 2 != 0) {
            // If n is odd, try (n, n-1, n-2)
            res = lcm3(n, n - 1, n - 2);
        } else {
            // If n is even, try (n, n-1, n-3)
            res = lcm3(n, n - 1, n - 3);
            // Also compare with (n-1, n-2, n-3)
            res = max(res, lcm3(n - 1, n - 2, n - 3));
        }

        return res;
    }
};
