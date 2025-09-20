#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> findExpr(string &s, int target) {
        vector<string> res;
        string expr;

        function<void(int,long long,long long,string)> dfs = [&](int idx, long long eval, long long prev, string path) {
            // If we've reached the end of the string
            if (idx == s.size()) {
                if (eval == target) {
                    res.push_back(path);
                }
                return;
            }

            long long num = 0;
            for (int i = idx; i < s.size(); i++) {
                // prevent leading zero numbers
                if (i > idx && s[idx] == '0') break;

                num = num * 10 + (s[i] - '0');
                string cur = s.substr(idx, i - idx + 1);

                if (idx == 0) {
                    // first number, no operator before it
                    dfs(i + 1, num, num, cur);
                } else {
                    dfs(i + 1, eval + num, num, path + "+" + cur);
                    dfs(i + 1, eval - num, -num, path + "-" + cur);
                    dfs(i + 1, eval - prev + prev * num, prev * num, path + "*" + cur);
                }
            }
        };

        dfs(0, 0, 0, "");
        sort(res.begin(), res.end()); // lexicographical order
        return res;
    }
};
