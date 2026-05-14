#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
  private:
    void topoSort(int u, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &st) {
        visited[u] = true;
        for (auto &edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                topoSort(v, adj, visited, st);
            }
        }
        st.push(u);
    }

  public:
    vector<int> maximumDistance(vector<vector<int>> edges, int n, int m, int src) {
        // Step 1: Build Adjacency List
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Step 2: Get Topological Sort
        stack<int> st;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topoSort(i, adj, visited, st);
            }
        }

        // Step 3: Initialize distances with INT_MIN
        vector<int> dist(n, INT_MIN);
        dist[src] = 0;

        // Step 4: Process vertices in topological order
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            // Only process nodes that have been reached from the source
            if (dist[u] != INT_MIN) {
                for (auto &edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    
                    // Relax edge for Longest Path
                    if (dist[u] + weight > dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        return dist;
    }
};