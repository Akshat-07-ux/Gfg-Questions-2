#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string chooseSwap(string &s) {
        int n = s.length();
        
        // Store the first occurrence index of each character 'a' through 'z'
        vector<int> first_pos(26, -1);
        for (int i = 0; i < n; i++) {
            int char_idx = s[i] - 'a';
            if (first_pos[char_idx] == -1) {
                first_pos[char_idx] = i;
            }
        }
        
        // Look for the first character that can be replaced by a smaller character
        for (int i = 0; i < n; i++) {
            bool found_swap = false;
            char char_to_replace = s[i];
            char smaller_char = ' ';
            
            // Check if any strictly smaller character appears after the current position
            for (char ch = 'a'; ch < s[i]; ch++) {
                if (first_pos[ch - 'a'] > i) {
                    smaller_char = ch;
                    found_swap = true;
                    break; // Pick the absolute smallest available character
                }
            }
            
            // If a valid swap pair is found, update all occurrences in the string
            if (found_swap) {
                for (int j = 0; j < n; j++) {
                    if (s[j] == char_to_replace) {
                        s[j] = smaller_char;
                    } else if (s[j] == smaller_char) {
                        s[j] = char_to_replace;
                    }
                }
                break; // We are allowed at most one swap operation
            }
        }
        
        return s;
    }
};