#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        const int MAX = 10000;
        vector<int> freq(MAX + 1, 0);
        for (int num : arr)
            freq[num]++;

        // Total pairs
        int total = arr.size();
        long long totalPairs = 1LL * total * (total - 1) / 2;

        // Count number of non-coprime pairs using a sieve-like method
        vector<int> countDivisible(MAX + 1, 0);
        for (int i = 1; i <= MAX; ++i) {
            for (int j = i; j <= MAX; j += i) {
                countDivisible[i] += freq[j];
            }
        }

        // mobius function for inclusion-exclusion
        vector<int> mobius(MAX + 1, 1);
        vector<bool> isPrime(MAX + 1, true);
        for (int i = 2; i <= MAX; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i; j <= MAX; j += i) {
                mobius[j] *= -1;
                isPrime[j] = false;
            }
            long long sq = 1LL * i * i;
            for (int j = sq; j <= MAX; j += sq) {
                mobius[j] = 0;
            }
        }

        // Inclusion-exclusion to count coprime pairs
        long long coPrimePairs = 0;
        for (int i = 1; i <= MAX; ++i) {
            if (mobius[i] == 0) continue;
            long long c = countDivisible[i];
            coPrimePairs += mobius[i] * (c * (c - 1LL) / 2);
        }

        return static_cast<int>(coPrimePairs);
    }
};
