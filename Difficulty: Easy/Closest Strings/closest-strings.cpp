#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int shortestDistance(vector<string> &s, string word1, string word2) {
        int idx1 = -1; // Tracks the latest index of word1
        int idx2 = -1; // Tracks the latest index of word2
        int min_dist = INT_MAX;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == word1) {
                idx1 = i;
            }
            if (s[i] == word2) {
                idx2 = i;
            }
            
            // If both words have been encountered at least once, calculate distance
            if (idx1 != -1 && idx2 != -1) {
                min_dist = min(min_dist, abs(idx1 - idx2));
            }
        }
        
        return min_dist;
    }
};