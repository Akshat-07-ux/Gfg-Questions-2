#include <vector>
#include <string>
using namespace std;

class Solution {
  public:

    vector<string> pattern(string& s) {
        vector<string> result;
        int n = s.size();
        
        // Loop from full length down to 1
        for (int i = n; i > 0; i--) {
            // Take substring from 0 to i characters
            result.push_back(s.substr(0, i));
        }
        
        return result;
    }
};
