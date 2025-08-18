#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1, 0);

        // Count citations
        for (int c : citations) {
            if (c >= n)
                count[n]++;
            else
                count[c]++;
        }

        int total = 0;
        // Traverse from back
        for (int i = n; i >= 0; i--) {
            total += count[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};
