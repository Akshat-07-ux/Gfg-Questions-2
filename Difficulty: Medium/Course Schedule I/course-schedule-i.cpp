class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph and indegree array
        for (auto &p : prerequisites) {
            int x = p[0]; // course to take
            int y = p[1]; // prerequisite
            graph[y].push_back(x);
            indegree[x]++;
        }

        queue<int> q;

        // Push courses with no prerequisites
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;

        // BFS Topological Sort
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completed++;

            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // If all courses are completed, return true
        return completed == n;
    }
};
