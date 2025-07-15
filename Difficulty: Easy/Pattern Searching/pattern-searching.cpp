// User function template for C++
class Solution {
  public:

    // Function to compute the Longest Prefix Suffix (LPS) array
    void computeLPSArray(string &pat, vector<int> &lps) {
        int length = 0;
        lps[0] = 0; // first character has no proper prefix/suffix

        int i = 1;
        while (i < pat.length()) {
            if (pat[i] == pat[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int search(string text, string pat) {
        int n = text.length();
        int m = pat.length();
        vector<int> lps(m, 0);

        computeLPSArray(pat, lps);

        int i = 0; // index for text
        int j = 0; // index for pat

        while (i < n) {
            if (text[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return 1; // match found
            } else if (i < n && text[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return 0; // pattern not found
    }
};
