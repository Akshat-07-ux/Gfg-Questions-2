class Solution {
public:

    bool isValid(string part) {
        if (part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    void solve(string &s, int index, int parts, string current, vector<string> &ans) {
        
        // If 4 parts are formed and entire string used
        if (parts == 4 && index == s.size()) {
            current.pop_back(); // remove last '.'
            ans.push_back(current);
            return;
        }

        // If invalid state
        if (parts >= 4 || index >= s.size())
            return;

        // Try taking 1 to 3 digits
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            
            string part = s.substr(index, len);

            if (isValid(part)) {
                solve(s, index + len, parts + 1, current + part + ".", ans);
            }
        }
    }

    vector<string> generateIp(string &s) {
        
        vector<string> ans;

        if (s.size() < 4 || s.size() > 12)
            return ans;

        solve(s, 0, 0, "", ans);

        return ans;
    }
};