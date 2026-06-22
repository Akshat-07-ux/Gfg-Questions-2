#include <string>

using namespace std;

class Solution {
  public:
    int countWords(string &s) {
        int wordCount = 0;
        bool inWord = false;
        
        for (char c : s) {
            // Check if the character is a lowercase English letter
            if (c >= 'a' && c <= 'z') {
                // If we were not already in a word, this marks the start of a new word
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                // It's a separator (' ', '\t', '\n'), so we are no longer in a word
                inWord = false;
            }
        }
        
        return wordCount;
    }
};