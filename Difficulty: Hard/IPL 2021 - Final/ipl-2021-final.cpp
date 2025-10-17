// User function template for C++
class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> st;
        st.push(-1); // base index for valid substring
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // push current index as base for next valid substring
                    st.push(i);
                } else {
                    // length of current valid substring
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};
