class Solution {
  public:
    int chinesePostmanProblem(vector<vector<int>> &e, int n) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        vector<int> degree(n, 0);
        int baseCost = 0;

        // Initialize graph
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (auto &edge : e) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];

            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);

            degree[u]++;
            degree[v]++;
            baseCost += w;
        }

        // Floyd-Warshall for all-pairs shortest paths
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // Collect odd-degree vertices
        vector<int> odd;
        for (int i = 0; i < n; i++)
            if (degree[i] % 2 == 1)
                odd.push_back(i);

        int m = odd.size();
        if (m == 0) return baseCost; // Already Eulerian

        // DP over subsets
        vector<int> dp(1 << m, INF);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << m); mask++) {
            int first = -1;
            for (int i = 0; i < m; i++) {
                if (!(mask & (1 << i))) {
                    first = i;
                    break;
                }
            }
            if (first == -1) continue;

            for (int j = first + 1; j < m; j++) {
                if (!(mask & (1 << j))) {
                    int newMask = mask | (1 << first) | (1 << j);
                    dp[newMask] = min(
                        dp[newMask],
                        dp[mask] + dist[odd[first]][odd[j]]
                    );
                }
            }
        }

        return baseCost + dp[(1 << m) - 1];
    }
};
