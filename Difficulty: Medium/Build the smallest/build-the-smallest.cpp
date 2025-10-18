string buildLowestNumber(string num, int k) {
    string result;

    for (char c : num) {
        // Remove larger digits from the left if possible
        while (!result.empty() && k > 0 && result.back() > c) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }

    // If k still remains, remove from the end
    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }

    // Remove leading zeros
    int i = 0;
    while (i < (int)result.size() && result[i] == '0') {
        i++;
    }

    result = result.substr(i);

    // Edge case: empty result → "0"
    return result.empty() ? "0" : result;
}
