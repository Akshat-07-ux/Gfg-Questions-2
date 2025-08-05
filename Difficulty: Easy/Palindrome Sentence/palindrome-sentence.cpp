#include <cctype> // for isalnum, tolower
using namespace std;

class Solution {
  public:
    bool isPalinSent(string &s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left index to next alphanumeric
            while (left < right && !isalnum(s[left])) left++;
            // Move right index to previous alphanumeric
            while (left < right && !isalnum(s[right])) right--;

            // Compare after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};
