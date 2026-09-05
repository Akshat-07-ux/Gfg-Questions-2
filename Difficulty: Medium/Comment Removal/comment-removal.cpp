class Solution {
public:
    string removeComments(string &s) {
        string result = "";
        bool single_line = false;
        bool multi_line = false;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            // If we are currently inside a single-line comment
            if (single_line) {
                // The comment ends when we encounter a newline or a literal "\n"
                if (s[i] == '\n') {
                    single_line = false;
                } else if (i + 1 < n && s[i] == '\\' && s[i + 1] == 'n') {
                    single_line = false;
                    i++; // Skip the 'n' character
                }
            } 
            // If we are currently inside a multi-line comment
            else if (multi_line) {
                // The comment ends when we encounter "*/"
                if (i + 1 < n && s[i] == '*' && s[i + 1] == '/') {
                    multi_line = false;
                    i++; // Skip the '/' character
                }
            } 
            // If we are traversing normal code
            else {
                // Check for the start of a single-line comment "//"
                if (i + 1 < n && s[i] == '/' && s[i + 1] == '/') {
                    single_line = true;
                    i++; // Skip the second '/'
                } 
                // Check for the start of a multi-line comment "/*"
                else if (i + 1 < n && s[i] == '/' && s[i + 1] == '*') {
                    multi_line = true;
                    i++; // Skip the '*'
                } 
                // Normal code characters are safely appended
                else {
                    result += s[i];
                }
            }
        }

        return result;
    }
};