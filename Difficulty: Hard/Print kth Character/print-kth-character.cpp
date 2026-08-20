#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findKthChar(string& s, long long k) {
        int n = s.length();

        // 1. Build Suffix Array
        vector<int> sa(n), rank(n), temp(n);
        for (int i = 0; i < n; ++i) {
            sa[i] = i;
            rank[i] = s[i];
        }

        for (int k_len = 1; k_len < n; k_len <<= 1) {
            auto cmp = [&](int i, int j) {
                if (rank[i] != rank[j]) return rank[i] < rank[j];
                int ri = (i + k_len < n) ? rank[i + k_len] : -1;
                int rj = (j + k_len < n) ? rank[j + k_len] : -1;
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                temp[sa[i]] = temp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            rank = temp;
            if (rank[sa[n - 1]] == n - 1) break;
        }

        // 2. Build LCP (Longest Common Prefix) array via Kasai's Algorithm
        vector<int> lcp(n, 0);
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (rank[i] > 0) {
                int j = sa[rank[i] - 1];
                while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                    h++;
                }
                lcp[rank[i]] = h;
                if (h > 0) h--;
            }
        }

        // 3. Iterate through unique substrings in lexicographical order
        for (int i = 0; i < n; ++i) {
            int suffix_idx = sa[i];
            int common_prefix = lcp[i];
            int max_len = n - suffix_idx;

            // Unique substrings from this suffix range from length (common_prefix + 1) to max_len
            for (int len = common_prefix + 1; len <= max_len; ++len) {
                if (k <= len) {
                    // The target character is at index (k - 1) of substring s[suffix_idx ... suffix_idx + len - 1]
                    return s[suffix_idx + k - 1];
                }
                k -= len;
            }
        }

        return ' ';
    }
};