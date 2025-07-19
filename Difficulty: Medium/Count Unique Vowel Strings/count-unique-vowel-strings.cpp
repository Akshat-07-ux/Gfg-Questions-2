#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char, vector<int>> vowelPos;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < s.size(); ++i) {
            if (vowels.count(s[i])) {
                vowelPos[s[i]].push_back(i);
            }
        }

        vector<char> uniqueVowels;
        for (char v : vowels) {
            if (vowelPos.count(v)) {
                uniqueVowels.push_back(v);
            }
        }

        int k = uniqueVowels.size();
        if (k == 0) return 0;
        if (k == 1) return vowelPos[uniqueVowels[0]].size(); // FIX: handle single vowel correctly

        // Backtracking for multiple vowels
        long long totalCount = 0;
        vector<int> indices(k);

        function<void(int)> dfs = [&](int idx) {
            if (idx == k) {
                long long perm = 1;
                for (int i = 2; i <= k; ++i) perm *= i;
                totalCount += perm;
                return;
            }

            char vowel = uniqueVowels[idx];
            for (int pos : vowelPos[vowel]) {
                indices[idx] = pos;
                dfs(idx + 1);
            }
        };

        dfs(0);

        return totalCount;
    }
};
