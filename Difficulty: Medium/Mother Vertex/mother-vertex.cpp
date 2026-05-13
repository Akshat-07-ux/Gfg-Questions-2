class Solution {
  public:
    // Helper function for DFS traversal
    void dfs(int u, vector<int> adj[], vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        int lastFinished = 0;

        // Step 1: Find the last finished vertex in DFS
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                lastFinished = i;
            }
        }

        // Step 2: Reset visited array and check if lastFinished is a Mother Vertex
        fill(visited.begin(), visited.end(), false);
        dfs(lastFinished, adj, visited);

        for (bool v : visited) {
            if (!v) return -1; // If any vertex is not reachable
        }

        // Step 3: Since the problem asks for the smallest index, and the 
        // candidate was the 'last' to finish, we check if any smaller index 
        // belongs to the same SCC as the lastFinished vertex.
        
        // Optimization/Refinement: If lastFinished can reach everything, 
        // any vertex that can reach lastFinished is also a Mother Vertex.
        // We check from 0 to V-1 to find the smallest index that can reach all.
        
        for (int i = 0; i < V; i++) {
            fill(visited.begin(), visited.end(), false);
            dfs(i, adj, visited);
            bool allReachable = true;
            for (bool v : visited) {
                if (!v) {
                    allReachable = false;
                    break;
                }
            }
            if (allReachable) return i;
            
            // Optimization: If the candidate found via DFS (lastFinished) 
            // is the smallest index, we can skip further checks. 
            // Most competitive programming cases accept the lastFinished 
            // logic if you find the 'first' node that finishes last.
            if (i >= lastFinished) break; 
        }

        return lastFinished;
    }
};