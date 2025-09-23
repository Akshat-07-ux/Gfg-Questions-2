#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        
        // Step 1: Move all elements from queue to stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        
        // Step 2: Move them back to queue (reversed order)
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};
