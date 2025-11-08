// User function template for C++
class Solution {
  public:
    int isPanagram(string S) {
        vector<bool> present(26, false);
        
        for (char c : S) {
            if (isalpha(c)) {
                c = tolower(c);
                present[c - 'a'] = true;
            }
        }
        
        // Check if all alphabets are present
        for (bool flag : present) {
            if (!flag) return 0;
        }
        return 1;
    }
};
