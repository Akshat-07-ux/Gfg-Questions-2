#include <vector>

class Solution {
  public:
    bool isNegativeWeightCycle(int V, std::vector<std::vector<int>>& edges) {
        // Initialize distances of all vertices to 0 to handle disconnected components
        std::vector<int> dist(V, 0);

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; ++i) {
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative weight cycle on the V-th relaxation
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] + weight < dist[v]) {
                return true; // Negative weight cycle detected
            }
        }

        return false; // No negative weight cycle
    }
};