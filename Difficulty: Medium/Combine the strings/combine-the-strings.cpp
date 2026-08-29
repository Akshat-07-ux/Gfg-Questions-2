#include <vector>
#include <string>
#include <algorithm>

class Solution {
  public:
    int combine(std::vector<std::string>& s) {
        int n = s.size();
        if (n == 0) return 0;

        int L = s[0].length();
        int cRR = 0, cRB = 0, cBR = 0, cBB = 0;

        // Categorize each string based on its first and last characters
        for (const std::string& str : s) {
            char start = str.front();
            char end = str.back();
            if (start == 'R' && end == 'R') cRR++;
            else if (start == 'R' && end == 'B') cRB++;
            else if (start == 'B' && end == 'R') cBR++;
            else if (start == 'B' && end == 'B') cBB++;
        }

        // Helper lambda to calculate maximum strings combined starting from a given state
        auto getMaxCombined = [&](char startState) -> int {
            int countRR = cRR, countRB = cRB, countBR = cBR, countBB = cBB;
            int totalStrings = 0;
            char currentState = startState;

            while (true) {
                if (currentState == 'R') {
                    // Consume all RR strings
                    totalStrings += countRR;
                    countRR = 0;
                    // Transition R -> B if possible
                    if (countRB > 0) {
                        totalStrings++;
                        countRB--;
                        currentState = 'B';
                    } else {
                        break;
                    }
                } else { // currentState == 'B'
                    // Consume all BB strings
                    totalStrings += countBB;
                    countBB = 0;
                    // Transition B -> R if possible
                    if (countBR > 0) {
                        totalStrings++;
                        countBR--;
                        currentState = 'R';
                    } else {
                        break;
                    }
                }
            }
            return totalStrings;
        };

        // Find the maximum strings we can combine starting with 'R' or 'B'
        int maxStrings = std::max(getMaxCombined('R'), getMaxCombined('B'));

        // If no two strings can be combined (maxStrings < 2), return 0
        if (maxStrings < 2) return 0;

        return maxStrings * L;
    }
};