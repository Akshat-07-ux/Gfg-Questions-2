class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int idx, string cur) {
        if (idx == s.size()) {
            ans.push_back(cur);
            return;
        }

        // Option 1: add with space
        dfs(s, idx + 1, cur + " " + s[idx]);

        // Option 2: add without space
        dfs(s, idx + 1, cur + s[idx]);
    }

    vector<string> permutation(string s) {
        ans.clear();
        
        // Start with the first character already placed
        dfs(s, 1, string(1, s[0]));

        sort(ans.begin(), ans.end());
        return ans;
    }
};
