class Solution {
  public:
    bool checkPath(int V, vector<vector<int>>& edges, int src, int dest) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // BFS
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            if (node == dest) return true;
            
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;
    }
};
