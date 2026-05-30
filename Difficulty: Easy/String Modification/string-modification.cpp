#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string rearrangeString(string str) {
        int n = str.length();
        if (n == 0) return "";

        // Step 1: Count frequencies of all characters
        vector<int> freq(26, 0);
        for (char ch : str) {
            freq[ch - 'a']++;
        }

        // Step 2: Find the character with the maximum frequency
        int max_freq = 0;
        char max_char = 'a';
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                max_char = (char)('a' + i);
            }
        }

        // Create a result string of the same size
        string res(n, ' ');
        int index = 0;

        // Step 3: Fill the most frequent character at alternate (even) indices
        while (max_freq > 0) {
            res[index] = max_char;
            index += 2;
            max_freq--;
        }
        
        // Decrement the count of the max character in our frequency array
        freq[max_char - 'a'] = 0;

        // Step 4: Fill the remaining characters in the remaining alternate slots
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                // If even indices are exhausted, switch to odd indices
                if (index >= n) {
                    index = 1;
                }
                res[index] = (char)('a' + i);
                index += 2;
                freq[i]--;
            }
        }

        return res;
    }
};