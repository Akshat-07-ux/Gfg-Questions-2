#include <string>
#include <cctype>

class Solution {
  public:
    // Function to convert the given string to Camel Case
    std::string convertToCamelCase(std::string& s) {
        std::string result = "";
        result.reserve(s.size()); // Pre-allocate memory for performance

        bool capitalizeNext = false;

        for (char ch : s) {
            if (ch == ' ') {
                capitalizeNext = true;
            } else {
                if (capitalizeNext) {
                    result += std::toupper(ch);
                    capitalizeNext = false;
                } else {
                    result += ch;
                }
            }
        }

        return result;
    }
};