class Solution {
  private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, 
             int disc[], int low[], vector<int> &mark) {
        vis[node] = 1;
        disc[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                child++;
                dfs(it, node, adj, vis, disc, low, mark);
                
                // Check if the child can reach back to node or above
                low[node] = min(low[node], low[it]);
                
                // Case 2: Non-root condition
                if (low[it] >= disc[node] && parent != -1) {
                    mark[node] = 1;
                }
            } else {
                // Back-edge: update low value
                low[node] = min(low[node], disc[it]);
            }
        }
        
        // Case 1: Root condition
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(V, 0);
        int disc[V];
        int low[V];
        vector<int> mark(V, 0); // Using a mark array to avoid duplicates

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, disc, low, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) ans.push_back(i);
        }

        if (ans.size() == 0) return {-1};
        return ans;
    }
};