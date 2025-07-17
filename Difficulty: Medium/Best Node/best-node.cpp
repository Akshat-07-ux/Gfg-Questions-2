class Solution {
  public:
    long long result = LLONG_MIN;

    void dfs(int node, vector<vector<int>> &tree, vector<int> &A, int sign, long long sum) {
        sum += sign * A[node];
        if (tree[node].empty()) {
            // Reached a leaf, check result
            result = max(result, sum);
            return;
        }
        for (int child : tree[node]) {
            dfs(child, tree, A, -sign, sum);
        }
    }

    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<vector<int>> tree(N);
        for (int i = 0; i < N; ++i) {
            if (P[i] != -1) {
                tree[P[i] - 1].push_back(i);
            }
        }

        // Try starting DFS from every node (since we can start anywhere)
        for (int i = 0; i < N; ++i) {
            dfs(i, tree, A, 1, 0);
        }

        return result;
    }
};
