#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // If start and end are already the same, 0 steps are needed.
        if (start == end) {
            return 0;
        }
        
        // Define the modulo limit
        const int MOD = 1000;
        
        // Array to store the minimum steps to reach each number.
        // Initialize with -1 to represent unvisited states.
        vector<int> dist(MOD, -1);
        
        // Queue for BFS storing the current number
        queue<int> q;
        
        // Initialize the starting point
        q.push(start);
        dist[start] = 0;
        
        // Standard BFS loop
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // Try multiplying the current value with every element in the array
            for (int num : arr) {
                // Calculate the next state
                int next = (1LL * curr * num) % MOD;
                
                // If this state hasn't been visited yet
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    
                    // If we reached the target, return the steps immediately
                    if (next == end) {
                        return dist[next];
                    }
                    
                    q.push(next);
                }
            }
        }
        
        // If the queue becomes empty and we haven't reached 'end'
        return -1;
    }
};