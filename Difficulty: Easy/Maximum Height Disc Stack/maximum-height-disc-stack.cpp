#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    // Fenwick Tree (Binary Indexed Tree) to keep track of maximum stack height
    class FenwickTree {
        vector<int> tree;
        int size;
      public:
        FenwickTree(int n) : size(n), tree(n + 1, 0) {}

        void update(int idx, int val) {
            for (; idx <= size; idx += idx & -idx) {
                tree[idx] = max(tree[idx], val);
            }
        }

        int query(int idx) const {
            int max_val = 0;
            for (; idx > 0; idx -= idx & -idx) {
                max_val = max(max_val, tree[idx]);
            }
            return max_val;
        }
    };

  public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();
        
        // Pair up radius and height for each disc
        vector<pair<int, int>> discs(n);
        int max_h = 0;
        for (int i = 0; i < n; ++i) {
            discs[i] = {r[i], h[i]};
            max_h = max(max_h, h[i]);
        }

        // Sort by radius ascending. 
        // For equal radii, sort by height descending to prevent using discs of equal radius.
        sort(discs.begin(), discs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        FenwickTree bit(max_h);
        int overall_max_height = 0;

        for (const auto& disc : discs) {
            int radius = disc.first;
            int height = disc.second;

            // Query maximum height achievable using discs with strictly smaller height
            int best_below = bit.query(height - 1);
            int current_stack_height = best_below + height;

            // Update Fenwick Tree with the new maximum height for this disc's height
            bit.update(height, current_stack_height);

            overall_max_height = max(overall_max_height, current_stack_height);
        }

        return overall_max_height;
    }
};