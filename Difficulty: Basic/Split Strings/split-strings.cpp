// User function Template for C++

class Solution {
  public:
    vector<string> splitString(string S) {
        string S1 = "", S2 = "", S3 = "";
        
        for (char ch : S) {
            if (isalpha(ch)) {
                S1 += ch;      // alphabets
            } 
            else if (isdigit(ch)) {
                S2 += ch;      // numbers
            } 
            else {
                S3 += ch;      // special characters
            }
        }
        
        vector<string> result;
        result.push_back(S1);
        result.push_back(S2);
        result.push_back(S3);
        
        return result;
    }
};
