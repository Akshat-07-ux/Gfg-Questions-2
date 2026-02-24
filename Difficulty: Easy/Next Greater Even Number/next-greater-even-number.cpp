#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    long long getNextEven(string x) {
        // Use next_permutation to find the next greater combination
        // next_permutation rearranges the string into the next lexicographically 
        // greater permutation.
        while (next_permutation(x.begin(), x.end())) {
            // Check if the current permutation is an even number
            // An even number must end in 0, 2, 4, 6, or 8
            int lastDigit = x.back() - '0';
            if (lastDigit % 2 == 0) {
                // stoll converts string to long long
                return stoll(x);
            }
        }
        
        // If the loop finishes without returning, no such number exists
        return -1;
    }
};