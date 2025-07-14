// User function Template for C++
class Solution {
  public:
    vector<vector<int>> adj;
    vector<vector<int>> dp;

    void dfs(int u, int parent) {
        dp[u][0] = 0; // u not selected
        dp[u][1] = 1; // u selected

        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs(v, u);

            dp[u][0] += dp[v][1]; // if u not selected, children must be selected
            dp[u][1] += min(dp[v][0], dp[v][1]); // if u selected, child may or may not be
        }
    }

    int countVertex(int N, vector<vector<int>> edges) {
        adj.assign(N + 1, vector<int>());
        dp.assign(N + 1, vector<int>(2, 0));

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0); // assuming node 1 is root

        return min(dp[1][0], dp[1][1]);
    }
};
