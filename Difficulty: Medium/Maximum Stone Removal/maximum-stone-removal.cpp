class Solution {
  public:

    void dfs(int node, vector<vector<int>>& stones, vector<int>& visited) {
        visited[node] = 1;

        for(int i = 0; i < stones.size(); i++) {
            if(!visited[i]) {
                // share same row or same column
                if(stones[i][0] == stones[node][0] || stones[i][1] == stones[node][1]) {
                    dfs(i, stones, visited);
                }
            }
        }
    }

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n, 0);
        int connectedComponents = 0;

        // Count number of connected components
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, stones, visited);
                connectedComponents++;
            }
        }

        // maximum stones removable = total stones - components
        return n - connectedComponents;
    }
};
