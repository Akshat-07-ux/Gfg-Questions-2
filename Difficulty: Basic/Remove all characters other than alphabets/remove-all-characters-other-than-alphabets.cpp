// User function template for C++
class Solution {
  public:
    string removeSpecialCharacter(string s) {
        string result = "";
        
        // Iterate through each character
        for (char c : s) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                result += c; // append only alphabets
            }
        }
        
        // If no alphabets found, return "-1"
        if (result.empty()) return "-1";
        
        return result;
    }
};
