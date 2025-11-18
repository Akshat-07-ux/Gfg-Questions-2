class Solution {
private:
    // Modulo constant for large number of ways
    const int MOD = 1e9 + 7; 

public:
    int countPaths(int V, std::vector<std::vector<int>>& edges) {
        // 1. Build Adjacency List
        // Adjacency list: adj[u] = { (v, time) ... }
        std::vector<std::vector<std::pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            // Undirected graph
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // 2. Initialization
        // dist[i]: minimum time to reach node i from node 0 (using long long for time)
        std::vector<long long> dist(V, std::numeric_limits<long long>::max());
        // ways[i]: number of ways to reach node i in the minimum time
        std::vector<int> ways(V, 0);

        // Min-priority queue: {time, node}
        // std::greater<std::pair<long long, int>> makes it a min-heap based on the first element (time)
        std::priority_queue<std::pair<long long, int>, 
                            std::vector<std::pair<long long, int>>, 
                            std::greater<std::pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {time, node}

        // 3. Dijkstra's Process
        while (!pq.empty()) {
            long long current_time = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Skip if this is a stale/longer path
            if (current_time > dist[u]) {
                continue;
            }

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                long long new_time = current_time + weight;

                // Case 1: Found a strictly shorter path
                if (new_time < dist[v]) {
                    dist[v] = new_time;
                    ways[v] = ways[u]; // The only way to reach v is through the ways to reach u
                    pq.push({dist[v], v});
                } 
                // Case 2: Found a path with the same shortest length
                else if (new_time == dist[v]) {
                    // Add the ways to reach u to the ways to reach v
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        // 4. Result
        return ways[V - 1];
    }
};