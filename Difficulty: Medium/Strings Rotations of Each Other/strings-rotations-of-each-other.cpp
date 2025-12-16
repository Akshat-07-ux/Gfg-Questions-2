class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // If lengths differ, rotation is impossible
        if (s1.length() != s2.length())
            return false;

        // Concatenate s1 with itself and check if s2 is a substring
        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
    }
};
