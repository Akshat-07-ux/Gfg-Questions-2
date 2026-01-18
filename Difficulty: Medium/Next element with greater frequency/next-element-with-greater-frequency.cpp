class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        unordered_map<int, int> freq;
        stack<int> st;

        // Step 1: Count frequencies
        for (int x : arr) {
            freq[x]++;
        }

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements with frequency <= current
            while (!st.empty() && freq[st.top()] <= freq[arr[i]]) {
                st.pop();
            }

            // If stack not empty, top is the answer
            if (!st.empty()) {
                result[i] = st.top();
            }

            // Push current element
            st.push(arr[i]);
        }

        return result;
    }
};
