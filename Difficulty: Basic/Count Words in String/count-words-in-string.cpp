// User function Template for C++
class Solution {
  public:
    int countWords(string &s) {
        int count = 1; // At least one word is always there as per constraints
        for (char c : s) {
            if (c == ' ') {
                count++;
            }
        }
        return count;
    }
};
