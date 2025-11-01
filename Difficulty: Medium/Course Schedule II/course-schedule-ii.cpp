#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // Create adjacency list
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Build graph
        for (auto &pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Queue for nodes with no prerequisites
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        
        // Kahn’s algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (auto &nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        // If topo sort includes all nodes → valid ordering
        if (topo.size() == n)
            return topo;
        
        // Else, cycle detected → return empty
        return {};
    }
};