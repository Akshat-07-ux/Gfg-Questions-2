// User function template for C++
class Solution {
  public:
    int isRepeat(string s) {
        int n = s.length();
        
        // Check all possible pattern lengths (divisors of n)
        for (int len = 1; len <= n/2; len++) {
            if (n % len == 0) {  // len must be a divisor of n
                string pattern = s.substr(0, len);
                string constructed = "";
                
                // Repeat the pattern n/len times
                int repetitions = n / len;
                for (int i = 0; i < repetitions; i++) {
                    constructed += pattern;
                }
                
                // Check if constructed string matches original
                if (constructed == s) {
                    return 1;
                }
            }
        }
        
        return 0;
    }
};