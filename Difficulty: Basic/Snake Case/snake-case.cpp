#include <string>
#include <cctype>

class Solution {
  public:
    std::string snakeCase(std::string &s) {
        std::string result = s;
        for (char &ch : result) {
            if (ch == ' ') {
                ch = '_';
            } else {
                ch = std::tolower(ch);
            }
        }
        return result;
    }
};