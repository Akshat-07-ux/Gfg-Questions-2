class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // Since we only care about lowercase English letters, 
        // an array of size 26 is sufficient.
        int charCounts[26] = {0};
        
        // Count the frequency of each character
        for (char c : s) {
            charCounts[c - 'a']++;
        }
        
        int oddCount = 0;
        
        // Count how many characters have an odd frequency
        for (int i = 0; i < 26; i++) {
            if (charCounts[i] % 2 != 0) {
                oddCount++;
            }
        }
        
        // If more than one character appears an odd number of times,
        // it's impossible to form a palindrome.
        return oddCount <= 1;
    }
};