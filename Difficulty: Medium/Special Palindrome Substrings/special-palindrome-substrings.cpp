#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int specialPalindrome(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int minOps = INT_MAX;

        // Try placing s2 starting at every valid index i in s1
        for (int i = 0; i <= n - m; ++i) {
            // Target array initialized with original characters of s1
            vector<char> target(s1.begin(), s1.end());
            // Fixed markers to know which indices are forced by s2
            vector<bool> fixed(n, false);

            bool possible = true;

            // Step 1: Force s2 into target at position i
            for (int j = 0; j < m; ++j) {
                target[i + j] = s2[j];
                fixed[i + j] = true;
            }

            // Step 2: Enforce palindrome symmetry across all symmetric pairs
            for (int l = 0; l < n / 2; ++l) {
                int r = n - 1 - l;

                if (fixed[l] && fixed[r]) {
                    // Both characters are fixed by s2; if they disagree, invalid placement
                    if (target[l] != target[r]) {
                        possible = false;
                        break;
                    }
                } else if (fixed[l]) {
                    // Left is fixed by s2, right must match
                    target[r] = target[l];
                } else if (fixed[r]) {
                    // Right is fixed by s2, left must match
                    target[l] = target[r];
                } else {
                    // Neither fixed: keep original match if already equal, 
                    // else pick target[l] as default
                    if (target[l] != target[r]) {
                        target[r] = target[l];
                    }
                }
            }

            if (!possible) continue;

            // Step 3: Count replacements from original s1 to target
            int ops = 0;
            for (int k = 0; k < n; ++k) {
                if (s1[k] != target[k]) {
                    ops++;
                }
            }

            minOps = min(minOps, ops);
        }

        return (minOps == INT_MAX) ? -1 : minOps;
    }
};