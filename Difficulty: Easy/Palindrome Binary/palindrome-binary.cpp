class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // We need to reverse the bits of n.
        // reversedN will store the bits of n in reverse order.
        unsigned int reversedN = 0;
        int temp = n;

        while (temp > 0) {
            // Shift reversedN to the left to make room for the next bit
            reversedN <<= 1;
            
            // If the current LSB of temp is 1, add it to reversedN
            if (temp & 1) {
                reversedN |= 1;
            }
            
            // Shift temp to the right to process the next bit
            temp >>= 1;
        }

        // If the reversed binary sequence equals the original, it's a palindrome
        return reversedN == n;
    }
};