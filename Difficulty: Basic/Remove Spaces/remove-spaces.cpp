class Solution {
  public:
    string removeSpaces(string& s) {
        // Use std::remove to shift all non-space characters to the front.
        // It returns an iterator to the new logical end of the string.
        auto new_end = std::remove(s.begin(), s.end(), ' ');
        
        // Erase the "garbage" characters from the new_end to the actual end.
        s.erase(new_end, s.end());
        
        return s;
    }
};