#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countSubsets(vector<int> &arr) {
        long long MOD = 1e9 + 7;

        // Primes up to 30
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        // Count frequencies of each number in arr
        vector<int> freq(31, 0);
        for (int x : arr) {
            freq[x]++;
        }

        // Map each square-free number x in [2, 30] to its prime bitmask
        vector<int> prime_mask(31, 0);
        for (int i = 2; i <= 30; ++i) {
            int temp = i;
            int mask = 0;
            bool is_square_free = true;

            for (int j = 0; j < 10; ++j) {
                int p = primes[j];
                int count = 0;
                while (temp % p == 0) {
                    count++;
                    temp /= p;
                }
                if (count > 1) { // Contains a prime factor squared
                    is_square_free = false;
                    break;
                }
                if (count == 1) {
                    mask |= (1 << j);
                }
            }

            if (is_square_free) {
                prime_mask[i] = mask;
            } else {
                prime_mask[i] = -1; // Flag non-square-free numbers
            }
        }

        // dp[mask] stores number of valid subsets yielding this prime mask
        vector<long long> dp(1 << 10, 0);
        dp[0] = 1; // Base case: empty subset

        // Process each unique number in [2, 30]
        for (int i = 2; i <= 30; ++i) {
            if (freq[i] == 0 || prime_mask[i] == -1) continue;

            int mask = prime_mask[i];
            long long count = freq[i];

            // Iterate backwards through bitmasks to avoid using the same number frequency twice
            for (int current_mask = (1 << 10) - 1; current_mask >= 0; --current_mask) {
                if ((current_mask & mask) == 0) {
                    dp[current_mask | mask] = (dp[current_mask | mask] + dp[current_mask] * count) % MOD;
                }
            }
        }

        // Sum all non-empty combinations (mask > 0)
        long long total_subsets = 0;
        for (int mask = 1; mask < (1 << 10); ++mask) {
            total_subsets = (total_subsets + dp[mask]) % MOD;
        }

        // Account for '1's in the input array: total_subsets * (2^freq[1]) + (2^freq[1] - 1) * total_subsets
        // Equivalently: total_subsets * 2^freq[1]
        long long pow2_ones = 1;
        for (int i = 0; i < freq[1]; ++i) {
            pow2_ones = (pow2_ones * 2) % MOD;
        }

        long long ans = (total_subsets * pow2_ones) % MOD;

        return ans;
    }
};