class Solution {
  public:
    string maxOdd(string s) {
        // Traverse from the end to find the last odd digit
        for (int i = s.size() - 1; i >= 0; i--) {
            int digit = s[i] - '0';
            if (digit % 2 == 1) {
                // Return substring from 0 to i (inclusive)
                return s.substr(0, i + 1);
            }
        }
        // No odd digit found → no odd substring possible
        return "";
    }
};
