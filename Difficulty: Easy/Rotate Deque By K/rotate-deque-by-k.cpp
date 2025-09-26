#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;
        
        k = k % n;  // effective rotations

        if (k == 0) return;

        if (type == 1) {
            // Right rotation
            // Move last k elements to front
            rotate(dq.begin(), dq.end() - k, dq.end());
        } else if (type == 2) {
            // Left rotation
            // Move first k elements to back
            rotate(dq.begin(), dq.begin() + k, dq.end());
        }
    }
};
