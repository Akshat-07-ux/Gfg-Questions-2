#include <vector>

class Solution {
  private:
    // Helper function to check if a number is a palindrome
    bool isPalindrome(int num) {
        int original = num;
        int reversed = 0;
        
        while (num > 0) {
            int digit = num % 10;
            // Prevent potential overflow, though not strictly an issue within 10^5
            if (reversed > (INT_MAX - digit) / 10) return false; 
            
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        
        return original == reversed;
    }

  public:
    std::vector<int> printPalindromes(int m, int n) {
        std::vector<int> result;
        
        for (int i = m; i <= n; i++) {
            if (isPalindrome(i)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};