class Solution {
  public:
    void clonestack(stack<int> st, stack<int>& cloned) {
        if (st.empty()) return;
        
        int x = st.top();
        st.pop();
        
        clonestack(st, cloned);
        
        cloned.push(x);
        st.push(x);
    }
};
