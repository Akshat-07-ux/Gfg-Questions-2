#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxIndexDifference(string &s) {
        int n = s.size();
        
        // max_reach_for_char[c] stores the farthest reachable index 
        // starting from character 'a' + c in the remaining right suffix
        vector<int> max_reach_for_char(26, -1);
        
        int max_diff = -1;

        // Traverse right to left
        for (int i = n - 1; i >= 0; --i) {
            int char_idx = s[i] - 'a';
            
            // Farthest index reachable starting from position i
            int current_farthest = i;
            
            // If the next consecutive letter ('a' + char_idx + 1) exists to the right,
            // we can jump to its best reachable position
            if (char_idx < 25 && max_reach_for_char[char_idx + 1] != -1) {
                current_farthest = max(current_farthest, max_reach_for_char[char_idx + 1]);
            }
            
            // Update the maximum reach for this character
            max_reach_for_char[char_idx] = max(max_reach_for_char[char_idx], current_farthest);
            
            // If current character is 'a', calculate difference with its farthest reach
            if (char_idx == 0) {
                max_diff = max(max_diff, current_farthest - i);
            }
        }

        return max_diff;
    }
};