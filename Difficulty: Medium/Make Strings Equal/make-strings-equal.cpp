class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) 
    {
        int n = s.size();
        const int INF = 1e9;

        // 26 x 26 cost matrix
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // cost to stay same is zero
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // fill given direct transformations
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd–Warshall to compute min cost between all char pairs
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;

        // for each position, choose best meeting character
        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if (a == b) continue; // already same

            long long best = LLONG_MAX;

            // try converting both to same target character c
            for (int c = 0; c < 26; c++) {
                if (dist[a][c] == INF || dist[b][c] == INF) continue;
                best = min(best, (long long)dist[a][c] + dist[b][c]);
            }

            if (best == LLONG_MAX) return -1; // impossible

            ans += best;
        }

        return ans;
    }
};
