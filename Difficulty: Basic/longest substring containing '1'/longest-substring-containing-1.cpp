int maxlength(string s) {
    int maxLen = 0, count = 0;
    for (char c : s) {
        if (c == '1') {
            count++;
            maxLen = max(maxLen, count);
        } else {
            count = 0;
        }
    }
    return maxLen;
}
