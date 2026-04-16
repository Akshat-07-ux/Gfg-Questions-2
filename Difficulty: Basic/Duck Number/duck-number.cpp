bool check_duck(string num) {
    int n = num.length();
    int i = 0;

    // 1. Skip leading zeros
    // We treat '0' at the start as non-significant
    while (i < n && num[i] == '0') {
        i++;
    }

    // 2. Look for '0' in the remaining significant digits
    // If we find a '0' after the first non-zero digit, it's a Duck Number
    while (i < n) {
        if (num[i] == '0') {
            return true;
        }
        i++;
    }

    // If we reach the end without finding a zero, it's not a Duck Number
    return false;
}