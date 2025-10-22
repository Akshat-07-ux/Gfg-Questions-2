#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        // Min-heap to store k+1 elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = arr.size();
        int index = 0;

        // Step 1: Insert first k+1 elements into the heap
        for (int i = 0; i <= k && i < n; i++)
            minHeap.push(arr[i]);

        // Step 2: Process remaining elements
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        // Step 3: Extract remaining elements from heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
