#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
    std::vector<int> search(std::string& pat, std::string& txt) {
        std::vector<int> result;
        int m = pat.size();
        int n = txt.size();

        if (m == 0 || n == 0 || m > n) {
            return result;
        }

        // Create lowercase copies for case-insensitive comparison
        std::string p = pat;
        std::string t = txt;
        for (char &c : p) c = std::tolower(c);
        for (char &c : t) c = std::tolower(c);

        // Step 1: Preprocess the pattern to create the LPS (Longest Prefix Suffix) array
        std::vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (p[i] == p[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Perform the KMP search
        i = 0; // index for t (text)
        int j = 0; // index for p (pattern)

        while (i < n) {
            if (p[j] == t[i]) {
                j++;
                i++;
            }

            if (j == m) {
                // Pattern found, calculate the 0-based starting index
                result.push_back(i - j);
                j = lps[j - 1]; // Reset j to find overlapping occurrences
            } else if (i < n && p[j] != t[i]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};