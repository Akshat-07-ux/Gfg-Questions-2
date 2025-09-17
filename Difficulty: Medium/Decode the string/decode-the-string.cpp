#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodedString(string &s) {
        stack<int> countStack;
        stack<string> strStack;
        string currStr = "";
        int k = 0;
        
        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0'); // build number in case of multiple digits
            }
            else if (ch == '[') {
                countStack.push(k);
                strStack.push(currStr);
                currStr = "";
                k = 0;
            }
            else if (ch == ']') {
                int repeat = countStack.top();
                countStack.pop();
                
                string temp = currStr;
                for (int i = 1; i < repeat; i++) {
                    currStr += temp; // repeat substring
                }
                
                currStr = strStack.top() + currStr;
                strStack.pop();
            }
            else {
                currStr += ch; // normal character
            }
        }
        
        return currStr;
    }
};
