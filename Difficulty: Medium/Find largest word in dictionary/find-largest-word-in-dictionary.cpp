// User function Template for C++
class Solution {
public:
    string findLongestWord(string S, vector<string> d) {
        string result = "";
        
        for (const string& word : d) {
            if (isSubsequence(word, S)) {
                // Check if this word is better than current result
                if (word.length() > result.length() || 
                    (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }
        
        return result;
    }
    
private:
    bool isSubsequence(const string& word, const string& S) {
        int i = 0; // pointer for word
        int j = 0; // pointer for S
        
        while (i < word.length() && j < S.length()) {
            if (word[i] == S[j]) {
                i++; // move to next character in word
            }
            j++; // always move to next character in S
        }
        
        // If we've matched all characters of word, it's a subsequence
        return i == word.length();
    }
};