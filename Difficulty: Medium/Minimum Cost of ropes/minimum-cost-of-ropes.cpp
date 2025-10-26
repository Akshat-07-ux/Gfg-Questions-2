#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // if there's only one rope, no cost
        if (arr.size() <= 1) return 0;

        // Min-heap to store rope lengths
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

        int totalCost = 0;

        // Keep connecting the two smallest ropes
        while (minHeap.size() > 1) {
            int first = minHeap.top();
            minHeap.pop();

            int second = minHeap.top();
            minHeap.pop();

            int cost = first + second;
            totalCost += cost;

            // push the new combined rope back into heap
            minHeap.push(cost);
        }

        return totalCost;
    }
};

