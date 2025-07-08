#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);

        // Step 1: Calculate frequencies
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Use stack to find next element with higher frequency
        stack<int> st; // stack stores indices

        for (int i = n - 1; i >= 0; --i) {
            // Pop elements that have freq <= current
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }

            // If stack not empty, that means top is the required element
            if (!st.empty()) {
                res[i] = arr[st.top()];
            }

            // Push current index
            st.push(i);
        }

        return res;
    }
};
