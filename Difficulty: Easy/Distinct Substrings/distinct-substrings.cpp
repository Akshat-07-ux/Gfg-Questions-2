int fun(string s) {
    unordered_set<string> st;
    for (int i = 0; i + 1 < (int)s.size(); i++) {
        st.insert(s.substr(i, 2));
    }
    return st.size();
}
