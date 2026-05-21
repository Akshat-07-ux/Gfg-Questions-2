#include <vector>
#include <string>

using namespace std;

class Solution {
  private:
    // Helper function to compute the LPS (Longest Prefix Suffix) array
    void computeLPSArray(string &pat, int M, vector<int> &lps) {
        int len = 0; // Length of the previous longest prefix suffix
        lps[0] = 0;  // lps[0] is always 0
        int i = 1;

        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Fall back to the previous best match
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

  public:
    vector<int> search(string &pat, string &txt) {
        int N = txt.length();
        int M = pat.length();
        
        vector<int> result;
        vector<int> lps(M);

        // Precompute the LPS array for the pattern
        computeLPSArray(pat, M, lps);

        int i = 0; // Index for txt
        int j = 0; // Index for pat
        
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                // A match is found! The starting index is (i - j)
                result.push_back(i - j);
                j = lps[j - 1]; // Reset j using the LPS array to find overlapping matches
            } 
            // Mismatch after j matches
            else if (i < N && pat[j] != txt[i]) {
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