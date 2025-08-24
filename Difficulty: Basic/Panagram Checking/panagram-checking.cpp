// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPanagram(string &s) {
        vector<bool> present(26, false);
        
        for (char c : s) {
            if (isalpha(c)) { // Only consider alphabets
                char lower = tolower(c);
                present[lower - 'a'] = true;
            }
        }
        
        for (bool found : present) {
            if (!found) return false; // If any letter missing
        }
        return true; // All letters present
    }
};
