class Solution {
  public:
    // Union-Find (Disjoint Set Union) data structure
    class DSU {
    public:
        vector<int> parent, rank;
        
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        bool unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            
            if (px == py) return false;
            
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
            return true;
        }
    };
    
    // Find MST weight and return edges used in MST
    pair<int, vector<int>> findMST(int V, vector<vector<int>> &edges, int skipEdge = -1) {
        // Sort edges by weight
        vector<int> indices(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            indices[i] = i;
        }
        
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return edges[a][2] < edges[b][2];
        });
        
        DSU dsu(V);
        int mstWeight = 0;
        int edgeCount = 0;
        vector<int> mstEdges;
        
        for (int idx : indices) {
            if (idx == skipEdge) continue;
            
            int u = edges[idx][0];
            int v = edges[idx][1];
            int w = edges[idx][2];
            
            if (dsu.unite(u, v)) {
                mstWeight += w;
                mstEdges.push_back(idx);
                edgeCount++;
                
                if (edgeCount == V - 1) break;
            }
        }
        
        // If we couldn't form a spanning tree
        if (edgeCount < V - 1) {
            return {-1, {}};
        }
        
        return {mstWeight, mstEdges};
    }
    
    int secondMST(int V, vector<vector<int>> &edges) {
        // Find the original MST
        auto [mstWeight, mstEdges] = findMST(V, edges);
        
        if (mstWeight == -1) return -1;
        
        int secondBest = INT_MAX;
        
        // Try removing each edge from the MST one by one
        for (int edgeIdx : mstEdges) {
            auto [weight, usedEdges] = findMST(V, edges, edgeIdx);
            
            // If a valid spanning tree exists and its weight is greater than MST
            if (weight != -1 && weight > mstWeight) {
                secondBest = min(secondBest, weight);
            }
        }
        
        return (secondBest == INT_MAX) ? -1 : secondBest;
    }
};