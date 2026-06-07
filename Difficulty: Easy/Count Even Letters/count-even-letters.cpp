class Solution {
public:
    int count(string& s) {
        // Array to store frequencies of characters 'a' through 'z'
        vector<int> freq(26, 0);
        
        // Count the occurrences of each character
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int evenCount = 0;
        
        // Check frequencies of all 26 possible lowercase English letters
        for (int i = 0; i < 26; i++) {
            // The character must appear in the string and have an even frequency
            if (freq[i] > 0 && freq[i] % 2 == 0) {
                evenCount++;
            }
        }
        
        return evenCount;
    }
};