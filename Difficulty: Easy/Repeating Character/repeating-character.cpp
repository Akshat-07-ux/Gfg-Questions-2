class Solution {
  public:
    int repeatedCharacter(string& s) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c]++;
        }
        
        // Find the first character (from left) that has frequency > 1
        for(int i = 0; i < s.length(); i++) {
            if(freq[s[i]] > 1) {
                return i;
            }
        }
        
        // If no character repeats, return -1
        return -1;
    }
};