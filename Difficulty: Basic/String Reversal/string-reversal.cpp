string reverseString(string s) {
    string result = "";
    bool seen[256] = {false}; // ASCII size to cover all characters

    for (int i = s.size() - 1; i >= 0; --i) {
        char ch = s[i];
        if (ch == ' ' || seen[(unsigned char)ch]) continue;
        seen[(unsigned char)ch] = true;
        result += ch;
    }

    return result;
}
