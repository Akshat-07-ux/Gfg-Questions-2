#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int findIndex(string &s) {
        int closing_count = 0;
        
        // Count the total number of closing brackets in the string
        for (char ch : s) {
            if (ch == ')') {
                closing_count++;
            }
        }
        
        // The index of the equal point is always equal to the 
        // total number of closing brackets.
        return closing_count;
    }
};