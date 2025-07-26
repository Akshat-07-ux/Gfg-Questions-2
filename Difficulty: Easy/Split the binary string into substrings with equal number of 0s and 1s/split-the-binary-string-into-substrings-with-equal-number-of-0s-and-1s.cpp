class Solution {
  public:
    int maxSubStr(string str) {
        int n = str.length();
        int balance = 0;  // +1 for '1', -1 for '0'
        int count = 0;    // count of balanced substrings
        
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                balance++;
            } else {
                balance--;
            }
            
            // When balance becomes 0, we found a balanced substring
            if (balance == 0) {
                count++;
            }
        }
        
        // If final balance is not 0, the string cannot be completely divided
        // into balanced substrings
        if (balance != 0) {
            return -1;
        }
        
        return count;
    }
};