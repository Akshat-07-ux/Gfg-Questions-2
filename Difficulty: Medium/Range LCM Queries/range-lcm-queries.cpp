#include <vector>
#include <numeric>

using namespace std;

class Solution {
    vector<long long> tree;
    int n;

    // Standard GCD function
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // LCM function using GCD
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Build the Segment Tree
    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    // Update the Segment Tree
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        
        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    // Query the LCM in range [L, R]
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 1; // Neutral element for LCM
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        long long left_lcm = query(2 * node, start, mid, l, r);
        long long right_lcm = query(2 * node + 1, mid + 1, end, l, r);
        return lcm(left_lcm, right_lcm);
    }

public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);

        vector<long long> results;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                // Update Query: [1, index, value]
                update(1, 0, n - 1, q[1], q[2]);
            } else if (q[0] == 2) {
                // Range Query: [2, L, R]
                results.push_back(query(1, 0, n - 1, q[1], q[2]));
            }
        }
        return results;
    }
};