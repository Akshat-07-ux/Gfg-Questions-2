#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
    // Helper function to find the prime factorization and update the max power of each prime
    void updatePrimeFactors(int num, map<int, int>& max_prime_powers) {
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                int count = 0;
                while (num % i == 0) {
                    count++;
                    num /= i;
                }
                max_prime_powers[i] = max(max_prime_powers[i], count);
            }
        }
        if (num > 1) {
            max_prime_powers[num] = max(max_prime_powers[num], 1);
        }
    }

public:
    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> visited(n + 1, false);
        map<int, int> max_prime_powers;
        long long MOD = 1e9 + 7;

        // Step 1: Find the lengths of all disjoint cycles
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int cycle_length = 0;
                int curr = i;
                
                // Traverse the cycle
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr - 1]; // 1-based to 0-based indexing
                    cycle_length++;
                }
                
                // Step 2: Track prime factors of the cycle length
                if (cycle_length > 0) {
                    updatePrimeFactors(cycle_length, max_prime_powers);
                }
            }
        }

        // Step 3: Compute the LCM modulo 10^9 + 7 using the accumulated prime powers
        long long ans = 1;
        for (auto const& [prime, power] : max_prime_powers) {
            for (int i = 0; i < power; ++i) {
                ans = (ans * prime) % MOD;
            }
        }

        return ans;
    }
};