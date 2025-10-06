// User function template for C++
class Solution {
  public:
    int divisibleBy4(string N) {
        int len = N.length();
        
        // If the number has only one digit
        if (len == 1) {
            int num = N[0] - '0';
            return (num % 4 == 0) ? 1 : 0;
        }
        
        // Take the last two digits only
        int lastTwo = (N[len - 2] - '0') * 10 + (N[len - 1] - '0');
        
        // Check divisibility
        return (lastTwo % 4 == 0) ? 1 : 0;
    }
};
