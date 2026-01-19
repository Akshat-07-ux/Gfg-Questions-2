class Solution {
  public:
    string removeKdig(string &s, int k) {
        string st;  // acts as a stack
        
        for (char c : s) {
            // Remove larger digits from the end if possible
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        
        // If removals are still left, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int idx = 0;
        while (idx < st.size() && st[idx] == '0') {
            idx++;
        }
        
        string result = st.substr(idx);
        
        return result.empty() ? "0" : result;
    }
};
