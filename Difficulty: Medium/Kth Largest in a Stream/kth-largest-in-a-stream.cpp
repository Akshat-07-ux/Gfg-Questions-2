#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> result;

        for (int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);

            // If heap size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }

            // If we have fewer than k elements, kth largest doesn't exist
            if (minHeap.size() < k) {
                result.push_back(-1);
            } else {
                // The top of the min-heap is the kth largest element
                result.push_back(minHeap.top());
            }
        }

        return result;
    }
};