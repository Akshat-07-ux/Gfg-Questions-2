#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string encode(vector<string>& arr) {
        string encodedStr = "";
        for (const string& str : arr) {
            encodedStr += to_string(str.length()) + "/:" + str;
        }
        return encodedStr;
    }

    vector<string> decode(string& s) {
        vector<string> result;
        int i = 0;
        int n = s.length();

        while (i < n) {
            // Find the position of the delimiter "/:" starting from i
            int delimPos = s.find("/:", i);

            // Extract the length of the upcoming string
            int len = stoi(s.substr(i, delimPos - i));

            // Move pointer past the length and the 2-character delimiter "/:"
            i = delimPos + 2;

            // Extract the original string using the parsed length
            result.push_back(s.substr(i, len));

            // Move pointer past the extracted string content
            i += len;
        }

        return result;
    }
};