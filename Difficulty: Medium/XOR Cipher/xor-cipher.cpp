class Solution {
  public:
    string deCypher(string &s) {
        int n = s.length();
        if (n == 0) return "";

        string orig = "";
        orig += s[0];
        int prev_val = hexCharToInt(s[0]);

        for (int i = 1; i < n; i++) {
            int curr_enc_val = hexCharToInt(s[i]);
            int orig_val = prev_val ^ curr_enc_val;
            orig += intToHexChar(orig_val);
            prev_val = orig_val;
        }

        return orig;
    }

private:
    int hexCharToInt(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        return c - 'A' + 10;
    }

    char intToHexChar(int n) {
        if (n >= 0 && n <= 9) return '0' + n;
        return 'A' + (n - 10);
    }
};