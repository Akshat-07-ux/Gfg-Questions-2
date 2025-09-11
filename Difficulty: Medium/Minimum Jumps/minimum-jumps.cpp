#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // Edge cases
        if (n <= 1) return 0;         // already at the last index
        if (arr[0] == 0) return -1;   // cannot move anywhere
        
        // Initialize
        int maxReach = arr[0];  // farthest index reachable
        int steps = arr[0];     // steps we can still take
        int jumps = 1;          // we made the first jump
        
        for (int i = 1; i < n; i++) {
            // If we reached the end
            if (i == n - 1) return jumps;
            
            // Update maxReach
            maxReach = max(maxReach, i + arr[i]);
            
            // Use a step
            steps--;
            
            // If no more steps left, we must jump
            if (steps == 0) {
                jumps++;
                
                // If current index is beyond maxReach, can't move
                if (i >= maxReach) return -1;
                
                // Reset steps for the new jump
                steps = maxReach - i;
            }
        }
        return -1; // If we never reach the end
    }
};