#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MOD = 1000003;

    int rank(string s) {
        int n = s.size();
        
        // Step 1: Check for duplicate characters
        vector<int> freq(256, 0);
        for (char c : s) {
            if (++freq[c] > 1) return 0;
        }

        // Step 2: Precompute factorials modulo MOD
        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        // Step 3: Calculate rank
        long long rank = 1;
        for (int i = 0; i < n; i++) {
            int smaller = 0;

            // Count chars smaller than s[i] to its right
            for (int j = i + 1; j < n; j++) {
                if (s[j] < s[i])
                    smaller++;
            }

            rank = (rank + smaller * fact[n - i - 1]) % MOD;
        }

        return (int)rank;
    }
};
