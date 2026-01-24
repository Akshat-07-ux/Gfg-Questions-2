#include <vector>
using namespace std;

class Solution {
  public:
    int isPallindrome(long long int N) {
        // Edge case: although constraints start at 1, 
        // 0 is technically a palindrome in binary.
        if (N == 0) return 1;

        vector<int> bits;
        
        // Extract all bits of N
        while (N > 0) {
            bits.push_back(N & 1); // Get the last bit
            N = N >> 1;            // Right shift N by 1
        }
        
        // Check if the vector 'bits' is a palindrome
        int left = 0;
        int right = bits.size() - 1;
        
        while (left < right) {
            if (bits[left] != bits[right]) {
                return 0; // Not a palindrome
            }
            left++;
            right--;
        }
        
        return 1; // Is a palindrome
    }
};