#include <string>
#include <algorithm>

class Solution {
  public:
    std::string rearrangeNoCba(std::string &s) {
        // Sorting the string places all 'a's before 'b's before 'c's.
        // This guarantees no 'c' appears before 'b' and no 'b' before 'a',
        // completely preventing "cba" as a subsequence while ensuring 
        // the string is lexicographically smallest.
        std::sort(s.begin(), s.end());
        return s;
    }
};