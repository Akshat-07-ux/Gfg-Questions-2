class Solution {
  public:

    // Disjoint Set Union (Union-Find)
    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        
        bool unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            if(px == py) return false;  // already connected (redundant)
            
            if(rank[px] < rank[py]) parent[px] = py;
            else if(rank[py] < rank[px]) parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
            return true;
        }
    };

    int minConnect(int V, vector<vector<int>>& edges) {

        DSU dsu(V);
        int redundant = 0;

        // Count redundant edges
        for(auto &e : edges){
            if(!dsu.unite(e[0], e[1])) {
                redundant++;  // this edge does not help in connectivity
            }
        }

        // Count components
        int components = 0;
        for(int i = 0; i < V; i++) {
            if(dsu.find(i) == i) components++;
        }

        // Minimum edges needed to connect all = components - 1
        int needed = components - 1;

        if(redundant >= needed) return needed;
        return -1; // Not enough redundant edges
    }
};
