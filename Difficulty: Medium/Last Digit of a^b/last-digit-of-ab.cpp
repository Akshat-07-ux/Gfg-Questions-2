#include <string>
#include <cmath>

using namespace std;

class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // Edge case: If exponent is "0", any number^0 is 1
        if (b == "0") return 1;
        
        // Edge case: If base is "0", 0^anything (except 0) is 0
        if (a == "0") return 0;
        
        // Find the last digit of the base string 'a'
        int last_a = a.back() - '0';
        
        // Find b % 4 using the last two digits of string 'b'
        int exp = 0;
        if (b.length() == 1) {
            exp = b[0] - '0';
        } else {
            // Take the last two characters
            int len = b.length();
            exp = (b[len - 2] - '0') * 10 + (b[len - 1] - '0');
        }
        
        // Calculate the effective exponent index in the cycle of 4
        int mod_exp = exp % 4;
        if (mod_exp == 0) {
            mod_exp = 4;
        }
        
        // Compute the last digit
        int result = pow(last_a, mod_exp);
        return result % 10;
    }
};