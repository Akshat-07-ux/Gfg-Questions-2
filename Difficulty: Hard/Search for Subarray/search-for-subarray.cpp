#include <vector>
using namespace std;

class Solution {
public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> result;

        if (m == 0) return result;

        // Step 1: Precompute the LPS (Longest Prefix Suffix) array for b
        vector<int> lps(m, 0);
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;
        
        while (i < m) {
            if (b[i] == b[len]) {
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

        // Step 2: Search for b in a using the LPS array
        int j = 0; // index for a[]
        int k = 0; // index for b[]
        
        while (j < n) {
            if (a[j] == b[k]) {
                j++;
                k++;
            }

            if (k == m) {
                // Found a match! Store the starting index
                result.push_back(j - k);
                k = lps[k - 1];
            } else if (j < n && a[j] != b[k]) {
                // Mismatch after k matches
                if (k != 0) {
                    k = lps[k - 1];
                } else {
                    j++;
                }
            }
        }

        return result;
    }
};