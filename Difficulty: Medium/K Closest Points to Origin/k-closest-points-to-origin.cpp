#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap that stores pairs of (distance squared, point)
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (auto &p : points) {
            int x = p[0], y = p[1];
            int dist = x * x + y * y; // no need to take sqrt
            
            maxHeap.push({dist, p});
            
            // Keep only k elements in the heap
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Extract the k closest points
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result; // order doesn't matter
    }
};
