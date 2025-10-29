#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Helper lambda for BFS to find farthest node and distance
        auto bfs = [&](int start) {
            vector<int> dist(V, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            
            int farthestNode = start;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neigh : adj[node]) {
                    if (dist[neigh] == -1) {
                        dist[neigh] = dist[node] + 1;
                        q.push(neigh);
                        if (dist[neigh] > dist[farthestNode])
                            farthestNode = neigh;
                    }
                }
            }
            return make_pair(farthestNode, dist[farthestNode]);
        };

        // Step 1: Find farthest from node 0
        auto first = bfs(0);

        // Step 2: Find farthest from that node
        auto second = bfs(first.first);

        // Diameter is the distance found in second BFS
        return second.second;
    }
};
