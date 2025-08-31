#include <bits/stdc++.h>
using namespace std;

int maxChars(string S) {
    vector<int> first(256, -1); // store first index of each char
    int maxDist = -1;

    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        if (first[c] == -1) {
            first[c] = i; // first time seeing this char
        } else {
            maxDist = max(maxDist, i - first[c] - 1);
        }
    }

    return maxDist;
}
