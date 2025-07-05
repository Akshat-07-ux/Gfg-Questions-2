#include <algorithm> // for transform
#include <cctype>    // for isupper, tolower, toupper

class Solution {
  public:
    string modify(string& s) {
        if (s.empty()) return s; // Safety check
        
        if (isupper(s[0])) {
            // Convert to uppercase
            transform(s.begin(), s.end(), s.begin(), ::toupper);
        } else {
            // Convert to lowercase
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }

        return s;
    }
};
