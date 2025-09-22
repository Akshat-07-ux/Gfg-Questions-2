#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);

        // Step 1: Previous smaller element (PSE)
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Step 2: Next smaller element (NSE)
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Step 3: Find length of window where arr[i] is minimum
        vector<int> ans(n + 1, INT_MIN);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }

        // Step 4: Fill missing values (propagate backwards)
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        // Step 5: Return result for sizes 1..n
        vector<int> res(n);
        for (int i = 1; i <= n; i++) res[i - 1] = ans[i];
        return res;
    }
};
