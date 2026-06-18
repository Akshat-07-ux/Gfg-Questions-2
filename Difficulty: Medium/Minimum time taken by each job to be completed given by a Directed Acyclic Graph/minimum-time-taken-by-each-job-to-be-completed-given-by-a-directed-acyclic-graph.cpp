#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        // Step 1: Create adjacency list and in-degree array (using 1-based indexing)
        vector<vector<int>> adj(n + 1);
        vector<int> in_degree(n + 1, 0);
        
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            in_degree[v]++;
        }
        
        // Step 2: Queue to store jobs with 0 in-degree and an array to store completion times
        queue<int> q;
        vector<int> time(n + 1, 0);
        
        // Push all jobs with no prerequisites into the queue
        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
                time[i] = 1; // Base jobs take 1 unit of time
            }
        }
        
        // Step 3: Process the jobs using BFS
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : adj[curr]) {
                in_degree[neighbor]--;
                
                // The completion time of the neighbor depends on the max time of its prerequisites
                time[neighbor] = max(time[neighbor], time[curr] + 1);
                
                // If all prerequisites are completed, push to queue
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: Construct the final 1-indexed output as required
        vector<int> ans(n);
        for (int i = 1; i <= n; i++) {
            ans[i - 1] = time[i];
        }
        
        return ans;
    }
};