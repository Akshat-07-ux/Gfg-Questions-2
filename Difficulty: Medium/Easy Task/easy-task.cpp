#include <string>
#include <vector>

using namespace std;

class FenwickTree {
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (++i; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }

    int query(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    int range_query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    vector<string> processQueries(string s, vector<vector<string>>& queries) {
        int n = s.length();

        // One Fenwick tree for each lowercase English letter ('a' through 'z')
        vector<FenwickTree> bit(26, FenwickTree(n));

        // Initialize Fenwick trees with the initial characters of string s
        for (int i = 0; i < n; ++i) {
            bit[s[i] - 'a'].add(i, 1);
        }

        vector<string> result;

        for (const auto& q : queries) {
            if (q[0] == "1") {
                // Type 1: Update query
                int idx = stoi(q[1]);
                char new_ch = q[2][0];
                char old_ch = s[idx];

                if (old_ch != new_ch) {
                    bit[old_ch - 'a'].add(idx, -1);
                    bit[new_ch - 'a'].add(idx, 1);
                    s[idx] = new_ch;
                }
            } else {
                // Type 2: Range k-th lexicographically largest character
                int left = stoi(q[1]);
                int right = stoi(q[2]);
                int k = stoi(q[3]);

                // Iterate from 'z' down to 'a' to find the k-th character in descending order
                for (int c = 25; c >= 0; --c) {
                    int count = bit[c].range_query(left, right);
                    if (k <= count) {
                        result.push_back(string(1, 'a' + c));
                        break;
                    }
                    k -= count;
                }
            }
        }

        return result;
    }
};