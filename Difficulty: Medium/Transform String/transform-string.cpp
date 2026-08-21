#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int transform(string &s1, string &s2) {
        // If lengths are different, transformation is impossible
        if (s1.length() != s2.length()) {
            return -1;
        }

        // Check character frequencies
        unordered_map<char, int> freq;
        for (char c : s1) freq[c]++;
        for (char c : s2) freq[c]--;

        for (auto const& [ch, count] : freq) {
            if (count != 0) {
                return -1; // Not anagrams
            }
        }

        // Calculate minimum operations using two pointers from the back
        int count = 0;
        int i = s1.length() - 1;
        int j = s2.length() - 1;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                j--;
            } else {
                count++;
            }
            i--;
        }

        return count;
    }
};