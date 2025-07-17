#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to get power of prime p in n!
    int countPowerInFactorial(int n, int p) {
        int count = 0;
        while (n) {
            n /= p;
            count += n;
        }
        return count;
    }

    int maxKPower(int n, int k) {
        int result = INT_MAX;
        // Prime factorize k
        for (int i = 2; i * i <= k; ++i) {
            int power = 0;
            while (k % i == 0) {
                ++power;
                k /= i;
            }
            if (power > 0) {
                int countInFact = countPowerInFactorial(n, i);
                result = min(result, countInFact / power);
            }
        }
        // If k is still > 1, it's a prime factor
        if (k > 1) {
            int countInFact = countPowerInFactorial(n, k);
            result = min(result, countInFact);
        }
        return result;
    }
};
