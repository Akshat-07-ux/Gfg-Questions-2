#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
  public:
    string findAndReplace(string S, int Q, int index[], string sources[],
                          string targets[]) {
        // We use a map to store valid replacements. 
        // Key: original index, Value: index in the input arrays
        map<int, int> validOps;

        for (int i = 0; i < Q; i++) {
            int startIdx = index[i];
            string src = sources[i];
            
            // Check if the source word exists at the given index in S
            // substr(start, length)
            if (S.substr(startIdx, src.length()) == src) {
                validOps[startIdx] = i;
            }
        }

        string result = "";
        for (int i = 0; i < S.length(); ) {
            // Check if there is a valid replacement starting at current index i
            if (validOps.count(i)) {
                int opIdx = validOps[i];
                result += targets[opIdx];
                // Skip the length of the source word in the original string
                i += sources[opIdx].length();
            } else {
                // No replacement here, keep the original character
                result += S[i];
                i++;
            }
        }

        return result;
    }
};