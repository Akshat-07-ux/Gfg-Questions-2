class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // Powers of 2 cannot be expressed as the sum of consecutive positive integers.
        // Also, 1 cannot be expressed as the sum of TWO or more consecutive positive numbers.
        if (n == 1) {
            return false;
        }
        
        // Bitwise trick to check if a number is a power of 2
        // If (n & (n - 1)) == 0, then n is a power of 2.
        return (n & (n - 1)) != 0;
    }
};