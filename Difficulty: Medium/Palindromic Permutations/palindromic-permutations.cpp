#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<string> allPalindromes(string &s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0;
        char midChar = '\0';
        string leftHalf = "";

        // Check character frequencies
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                midChar = (char)('a' + i);
            }
            // Append half of the occurrences to the left half base string
            leftHalf.append(freq[i] / 2, (char)('a' + i));
        }

        // More than 1 odd frequency means no palindrome can be formed
        if (oddCount > 1) {
            return {};
        }

        // Sort leftHalf to start generating permutations in lexicographical order
        sort(leftHalf.begin(), leftHalf.end());

        vector<string> result;
        do {
            string rightHalf = leftHalf;
            reverse(rightHalf.begin(), rightHalf.end());

            string fullPalindrome = leftHalf;
            if (oddCount == 1) {
                fullPalindrome += midChar;
            }
            fullPalindrome += rightHalf;

            result.push_back(fullPalindrome);
        } while (next_permutation(leftHalf.begin(), leftHalf.end()));

        return result;
    }
};