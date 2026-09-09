class Solution {
  public:
    string longestDescAP(string& s) {
        bool present[26] = {false};
        for (char c : s) {
            present[c - 'A'] = true;
        }

        string res = "";
        int bestDiff = INT_MAX;

        for (int start = 25; start >= 0; start--) {
            for (int diff = 1; diff <= 25; diff++) {
                string cur = "";
                for (int x = start; x >= 0; x -= diff) {
                    if (present[x]) {
                        cur += (char)('A' + x);
                    } else {
                        break;
                    }
                }

                if (cur.length() > res.length() || 
                    (cur.length() == res.length() && diff < bestDiff) || 
                    (cur.length() == res.length() && diff == bestDiff && cur > res)) {
                    res = cur;
                    bestDiff = diff;
                }
            }
        }
        return res;
    }
};