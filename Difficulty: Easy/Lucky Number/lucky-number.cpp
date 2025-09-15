#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isLuckyOrNot(long long N) {
        string s = to_string(N);
        int n = s.size();
        unordered_set<long long> products;

        // iterate over all sub-numbers
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = i; j < n; j++) {
                int digit = s[j] - '0';
                prod *= digit;

                // check if this product already exists
                if (products.count(prod)) {
                    return 0; // not lucky
                }
                products.insert(prod);
            }
        }
        return 1; // lucky
    }
};
