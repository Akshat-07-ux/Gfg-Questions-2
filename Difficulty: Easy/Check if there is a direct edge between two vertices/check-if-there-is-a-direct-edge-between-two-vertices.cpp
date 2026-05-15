class Solution {
  public:
    bool checkEdge(vector<vector<int>>& adj, int u, int v) {
        // Access the list of neighbors for vertex u
        // We iterate through every neighbor 'neighbor' in adj[u]
        for (int neighbor : adj[u]) {
            // If we find v in u's adjacency list, a direct edge exists
            if (neighbor == v) {
                return true;
            }
        }
        
        // If the loop finishes without finding v, no direct edge exists
        return false;
    }
};