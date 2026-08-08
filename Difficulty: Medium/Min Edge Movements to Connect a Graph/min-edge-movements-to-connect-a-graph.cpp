#include <vector>
#include <numeric>

class Solution {
private:
    struct DSU {
        std::vector<int> parent;
        int components;

        DSU(int n) : parent(n), components(n) {
            std::iota(parent.begin(), parent.end(), 0);
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]); // Path compression
        }

        void unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                components--; // Reduce component count when merging
            }
        }
    };

public:
    int minEdgesReq(int n, std::vector<std::vector<int>>& edges) {
        int m = edges.size();

        // A connected graph of 'n' vertices requires at least 'n - 1' edges.
        if (m < n - 1) {
            return -1;
        }

        DSU dsu(n);
        for (const auto& edge : edges) {
            dsu.unite(edge[0], edge[1]);
        }

        // To connect 'C' components, we need 'C - 1' edges/operations.
        return dsu.components - 1;
    }
};