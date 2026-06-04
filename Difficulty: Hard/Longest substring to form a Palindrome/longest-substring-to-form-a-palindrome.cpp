#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int longestSubstring(string S) {
        int n = S.length();
        
        // Map to store the earliest index where a specific bitmask was seen.
        // Key: bitmask (int), Value: index (int)
        unordered_map<int, int> first_occurrence;
        
        // Base case: Before processing any character, the mask is 0 at index -1.
        first_occurrence[0] = -1;
        
        int current_mask = 0;
        int max_len = 0;
        
        for (int j = 0; j < n; ++j) {
            // Flip the bit corresponding to the current character
            int char_idx = S[j] - 'a';
            current_mask ^= (1 << char_idx);
            
            // Case 1: Check if this exact mask has been seen before (All even counts)
            if (first_occurrence.find(current_mask) != first_occurrence.end()) {
                max_len = max(max_len, j - first_occurrence[current_mask]);
            } else {
                // Store it only if it's the first time we see it to maximize length
                first_occurrence[current_mask] = j;
            }
            
            // Case 2: Check if a mask differing by exactly one bit has been seen before (One odd count)
            for (int i = 0; i < 26; ++i) {
                int look_for_mask = current_mask ^ (1 << i);
                if (first_occurrence.find(look_for_mask) != first_occurrence.end()) {
                    max_len = max(max_len, j - first_occurrence[look_for_mask]);
                }
            }
        }
        
        return max_len;
    }
};