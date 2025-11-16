int Count(string S) {
    int count = 0;
    for (char c : S) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            count++;
        }
    }
    return count;
}
