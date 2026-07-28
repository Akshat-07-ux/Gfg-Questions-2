#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // Build adjacency list: adj[u] contains pairs of {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Undirected graph
        }

        // Min-heap storing pairs of {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Distance array initialized to infinity (1e9)
        vector<int> dist(V, 1e9);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Early exit if we reach the destination
            if (u == dest) return d;

            // Skip processing if a shorter path to u has already been found
            if (d > dist[u]) continue;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dest] == 1e9 ? -1 : dist[dest];
    }
};