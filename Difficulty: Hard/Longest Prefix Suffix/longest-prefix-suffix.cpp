class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);  // LPS array initialization
        int len = 0;  // length of the previous longest prefix suffix

        for (int i = 1; i < n; ++i) {
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];  // backtrack
            }
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
            }
            // else lps[i] is already 0
        }

        return lps[n - 1];  // longest proper prefix which is also suffix
    }
};
