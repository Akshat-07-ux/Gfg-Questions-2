class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> s; // Stack to store indices of the prices

        for (int i = 0; i < n; i++) {
            // Pop elements from stack while stack is not empty 
            // and the current price is greater than or equal to price at stack top
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }

            // If stack is empty, then current price is greater than all previous elements
            // Otherwise, span is the difference between current index and next greater index
            if (s.empty()) {
                span[i] = i + 1;
            } else {
                span[i] = i - s.top();
            }

            // Push this element's index to stack
            s.push(i);
        }
        
        return span;
    }
};