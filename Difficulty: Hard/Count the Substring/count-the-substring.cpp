#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    vector<int> bit;
    int n;
  public:
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

class Solution {
  public:
    long long countSubstring(string S) {
        int n = S.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (S[i] == '1' ? 1 : -1);
        }

        // Coordinate compression of prefix sums
        vector<int> sortedVals = prefix;
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());

        auto getIndex = [&](int x) {
            return int(lower_bound(sortedVals.begin(), sortedVals.end(), x) - sortedVals.begin()) + 1;
        };

        Fenwick bit(sortedVals.size());
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            int idx = getIndex(prefix[i]);
            // Count how many prefix sums < current prefix[i]
            ans += bit.query(idx - 1);
            // Add current prefix sum to BIT
            bit.update(idx, 1);
        }

        return ans;
    }
};
