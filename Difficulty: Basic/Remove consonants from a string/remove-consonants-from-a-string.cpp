
class Solution {
  public:
    string removeConsonants(string s) {
        string result = "";
        for (char c : s) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                result += c;
            }
        }
        return result.empty() ? "No Vowel" : result;
    }
};