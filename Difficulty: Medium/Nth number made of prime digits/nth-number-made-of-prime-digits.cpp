#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int primeDigits(int n) {
        vector<int> primes = {2, 3, 5, 7};
        queue<long long> q;

        // push base primes
        for (int p : primes) q.push(p);

        int count = 0;
        long long num = 0;

        // BFS-like generation
        while (!q.empty()) {
            num = q.front();
            q.pop();
            count++;

            if (count == n) return num;

            // Append each prime digit to the current number
            for (int p : primes) {
                q.push(num * 10 + p);
            }
        }
        return -1; // (should never happen for given constraints)
    }
};

