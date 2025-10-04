#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> ans;

    void backtrack(string &s, int target, int idx, long long currVal, long long prevNum, string expr) {
        // Base case: if we reach end of string
        if (idx == s.size()) {
            if (currVal == target) ans.push_back(expr);
            return;
        }
        
        // Form numbers by picking digits one by one
        for (int i = idx; i < s.size(); i++) {
            // Avoid numbers with leading zero
            if (i > idx && s[idx] == '0') break;

            string part = s.substr(idx, i - idx + 1);
            long long num = stoll(part);

            if (idx == 0) {
                // First number, start expression
                backtrack(s, target, i + 1, num, num, part);
            } else {
                // '+' operator
                backtrack(s, target, i + 1, currVal + num, num, expr + "+" + part);
                // '-' operator
                backtrack(s, target, i + 1, currVal - num, -num, expr + "-" + part);
                // '*' operator (handle precedence)
                backtrack(s, target, i + 1, currVal - prevNum + prevNum * num, prevNum * num, expr + "*" + part);
            }
        }
    }

    vector<string> findExpr(string &s, int target) {
        ans.clear();
        backtrack(s, target, 0, 0, 0, "");
        sort(ans.begin(), ans.end()); // Lexicographically smallest order
        return ans;
    }
};
