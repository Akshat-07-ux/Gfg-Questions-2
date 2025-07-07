#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n, -1); // Initialize result with -1
        stack<int> st; // Stack stores indices

        // Traverse the array twice to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; --i) {
            int index = i % n;
            
            // Pop smaller elements from stack
            while (!st.empty() && arr[st.top()] <= arr[index]) {
                st.pop();
            }

            // If stack is not empty, top is the next greater element
            if (!st.empty()) {
                result[index] = arr[st.top()];
            }

            // Push current index onto the stack
            st.push(index);
        }

        return result;
    }
};
