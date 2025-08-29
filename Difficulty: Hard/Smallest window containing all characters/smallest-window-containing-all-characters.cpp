#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        // Frequency arrays for lowercase letters
        vector<int> need(26, 0), have(26, 0);

        // Fill need[]
        for (char c : p) need[c - 'a']++;

        int required = 0; 
        for (int x : need) if (x > 0) required++;

        int formed = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX, start = -1;

        while (right < s.size()) {
            char c = s[right];
            have[c - 'a']++;

            if (need[c - 'a'] > 0 && have[c - 'a'] == need[c - 'a'])
                formed++;

            // When all required chars are satisfied
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Try to shrink window
                char d = s[left];
                have[d - 'a']--;
                if (need[d - 'a'] > 0 && have[d - 'a'] < need[d - 'a'])
                    formed--;

                left++;
            }
            right++;
        }

        if (start == -1) return "";
        return s.substr(start, minLen);
    }
};


