#include <string>
#include <cctype>

using namespace std;

class Solution {
  public:
    string compressString(string &s) {
        string result = "";
        int n = s.length();
        int i = 0;
        
        while (i < n) {
            char currChar = tolower(s[i]);
            int j = i;
            
            // Count consecutive identical characters (case-insensitive)
            while (j < n && tolower(s[j]) == currChar) {
                j++;
            }
            
            int count = j - i;
            
            // Append lowercase character and its count
            result += currChar;
            result += to_string(count);
            
            // Move to the start of the next group
            i = j;
        }
        
        return result;
    }
};