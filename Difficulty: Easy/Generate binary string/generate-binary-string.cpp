class Solution {
  public:
    void solve(int idx, string &s, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }
        
        if (s[idx] == '?') {
            s[idx] = '0';
            solve(idx + 1, s, ans);
            
            s[idx] = '1';
            solve(idx + 1, s, ans);
            
            s[idx] = '?'; // backtrack
        } else {
            solve(idx + 1, s, ans);
        }
    }
    
    vector<string> generate_binary_string(string s) {
        vector<string> ans;
        solve(0, s, ans);
        return ans;
    }
};
