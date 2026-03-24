class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // 1. Create adjacency list and in-degree array
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int dependency = pre[1];
            // The problem says [x, y] means y must be taken before x
            // So the edge is dependency -> course
            adj[dependency].push_back(course);
            inDegree[course]++;
        }

        // 2. Add all nodes with 0 in-degree to the queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. Process the queue
        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. If we processed all nodes, there is no cycle
        return count == n;
    }
};