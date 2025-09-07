class Solution {
  public:
    string reverse(string str) {
        int i = 0, j = str.size() - 1;
        
        while (i < j) {
            // Skip non-alphabet chars from left
            if (!isalpha(str[i])) {
                i++;
            }
            // Skip non-alphabet chars from right
            else if (!isalpha(str[j])) {
                j--;
            }
            // Both are alphabets -> swap
            else {
                swap(str[i], str[j]);
                i++;
                j--;
            }
        }
        
        return str;
    }
};
