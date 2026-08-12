#include <string>

using namespace std;

class Solution {
  public:
    string combineStrings(string &a, string &b) {
        if (a.length() < b.length()) {
            return a + b + a;
        } else {
            return b + a + b;
        }
    }
};