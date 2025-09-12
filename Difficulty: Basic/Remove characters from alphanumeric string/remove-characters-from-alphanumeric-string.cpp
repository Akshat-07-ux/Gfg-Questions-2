// User function template for C++
class Solution {
  public:
    string removeCharacters(string& s) {
        string result = "";
        for (char ch : s) {
            if (isdigit(ch)) {
                result.push_back(ch);
            }
        }
        return result;
    }
};
