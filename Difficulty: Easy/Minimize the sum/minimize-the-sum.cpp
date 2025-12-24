class Solution {
  public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Insert all elements into the min-heap
        for (int x : arr) {
            minHeap.push(x);
        }

        int totalSum = 0;

        // Combine elements until only one remains
        while (minHeap.size() > 1) {
            int a = minHeap.top(); minHeap.pop();
            int b = minHeap.top(); minHeap.pop();

            int sum = a + b;
            totalSum += sum;

            minHeap.push(sum);
        }

        return totalSum;
    }
};
