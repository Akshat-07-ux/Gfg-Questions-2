#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string rearrange(string S, int N) {
        vector<char> vowels, consonants;
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        // Separate vowels and consonants
        for (char ch : S) {
            if (isVowel(ch))
                vowels.push_back(ch);
            else
                consonants.push_back(ch);
        }

        int v = vowels.size();
        int c = consonants.size();

        // Impossible case: difference greater than 1
        if (abs(v - c) > 1) return "-1";

        // Sort both groups for lexicographical ordering
        sort(vowels.begin(), vowels.end());
        sort(consonants.begin(), consonants.end());

        string res1 = "", res2 = "";

        // Helper to merge two lists alternatively
        auto merge = [](const vector<char>& a, const vector<char>& b) {
            string res = "";
            int n = a.size(), m = b.size();
            for (int i = 0; i < min(n, m); ++i) {
                res += a[i];
                res += b[i];
            }
            if (n > m) res += a.back();
            return res;
        };

        string ans = "";

        // Try vowel first if vowels are more or equal and result is valid
        if (v >= c) {
            string temp = merge(vowels, consonants);
            if (temp.size() == N)
                ans = temp;
        }

        // Try consonant first if consonants are more or equal and result is valid
        if (c >= v) {
            string temp = merge(consonants, vowels);
            if (temp.size() == N) {
                if (ans.empty() || temp < ans)
                    ans = temp;
            }
        }

        return ans.empty() ? "-1" : ans;
    }
};
