class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        int half = n / 2;
        queue<int> firstHalf;

        // Step 1: Push the first half of elements into a temporary queue
        for (int i = 0; i < half; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Step 2: Interleave elements back into the original queue
        // Original queue now only contains the second half
        while (!firstHalf.empty()) {
            // Add element from first half
            q.push(firstHalf.front());
            firstHalf.pop();
            
            // Move the current front of q (from the second half) to the back
            q.push(q.front());
            q.pop();
        }
    }
};