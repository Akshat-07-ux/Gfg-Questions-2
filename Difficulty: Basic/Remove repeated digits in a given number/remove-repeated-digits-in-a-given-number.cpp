long long int modify(long long int N) {
    string s = to_string(N);
    string result;
    
    result.push_back(s[0]); // first digit always stays
    
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            result.push_back(s[i]);
        }
    }
    
    // convert back to integer
    return stoll(result);
}
