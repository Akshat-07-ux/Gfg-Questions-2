int solve(string N) {
    // Array to store frequency of each digit (0-9)
    int freq[10] = {0};
    
    // Count frequency of each digit
    for (char c : N) {
        freq[c - '0']++;
    }
    
    // Find the digit with maximum frequency
    // In case of tie, we want the larger digit, so traverse from 9 to 0
    int maxFreq = 0;
    int result = 0;
    
    for (int i = 9; i >= 0; i--) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            result = i;
        }
    }
    
    return result;
}