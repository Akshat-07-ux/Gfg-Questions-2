#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string LexicographicallyMinimum(string str) {
        int n = str.length();
        
        // Array to store the first occurrence index of each character 'a'-'z'.
        // Initialize with -1 to signify the character hasn't appeared yet.
        vector<int> first_occ(26, -1);
        for (int i = 0; i < n; i++) {
            int char_idx = str[i] - 'a';
            if (first_occ[char_idx] == -1) {
                first_occ[char_idx] = i;
            }
        }
        
        // Scan the string from left to right to find the first improvable character
        for (int i = 0; i < n; i++) {
            // Check if there's a smaller character available that appears after position 'i'
            for (char ch = 'a'; ch < str[i]; ch++) {
                int smaller_char_idx = ch - 'a';
                
                // If the smaller character exists in the string and appears after index i
                if (first_occ[smaller_char_idx] > i) {
                    char char_to_swap_with = str[i];
                    char target_char = ch;
                    
                    // Replace all occurrences of both characters
                    for (int j = 0; j < n; j++) {
                        if (str[j] == char_to_swap_with) {
                            str[j] = target_char;
                        } else if (str[j] == target_char) {
                            str[j] = char_to_swap_with;
                        }
                    }
                    
                    // We can only do this operation at most once, so return immediately
                    return str;
                }
            }
        }
        
        // If no optimal swap was found, the original string is already the minimum
        return str;
    }
};