class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges_list) {
        // Convert edge list to an adjacency array for O(1) lookup
        // Since each node has at most one outgoing edge:
        vector<int> adj(V, -1);
        for (auto& edge : edges_list) {
            adj[edge[0]] = edge[1];
        }

        vector<int> visited(V, 0); // 0: unvisited, 1: visiting, 2: processed
        int maxCycleLen = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                // Store {node: distance_from_start_of_traversal}
                unordered_map<int, int> dist;
                int curr = i;
                int d = 0;

                while (curr != -1 && visited[curr] != 2) {
                    if (visited[curr] == 1) {
                        // Cycle detected!
                        maxCycleLen = max(maxCycleLen, d - dist[curr]);
                        break;
                    }

                    visited[curr] = 1; // Mark as visiting
                    dist[curr] = d;
                    curr = adj[curr];
                    d++;
                }

                // Mark all nodes in this path as fully processed
                int cleanup = i;
                while (cleanup != -1 && visited[cleanup] != 2) {
                    visited[cleanup] = 2;
                    cleanup = adj[cleanup];
                }
            }
        }

        return maxCycleLen;
    }
};