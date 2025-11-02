// User function Template for C++
class Solution {
  public:
    bool searchPattern(string& txt, string& pat) {
        // Use the built-in string find() method
        // find() returns npos if substring is not found
        return txt.find(pat) != string::npos;
    }
};
