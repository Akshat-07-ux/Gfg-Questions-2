// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

string lexicographicalSmallestString(string& s) {
    int n = s.size();

    // Step 1: Check single characters
    vector<bool> present(26, false);
    for (char c : s) {
        present[c - 'a'] = true;
    }
    for (int i = 0; i < 26; i++) {
        if (!present[i]) {
            return string(1, 'a' + i);
        }
    }

    // Step 2: Check substrings of length 2
    unordered_set<string> subs2;
    for (int i = 0; i + 1 < n; i++) {
        subs2.insert(s.substr(i, 2));
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            string candidate;
            candidate.push_back('a' + i);
            candidate.push_back('a' + j);
            if (subs2.find(candidate) == subs2.end()) {
                return candidate;
            }
        }
    }

    // Step 3: Check substrings of length 3
    unordered_set<string> subs3;
    for (int i = 0; i + 2 < n; i++) {
        subs3.insert(s.substr(i, 3));
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                string candidate;
                candidate.push_back('a' + i);
                candidate.push_back('a' + j);
                candidate.push_back('a' + k);
                if (subs3.find(candidate) == subs3.end()) {
                    return candidate;
                }
            }
        }
    }

    return ""; // theoretically never reached for given constraints
}
