class Solution {
  public:
    int minParentheses(string& s) {
        int open = 0;   // count of unmatched '('
        int close = 0;  // count of unmatched ')'
        
        for (char c : s) {
            if (c == '(') {
                open++; // new open bracket
            } else { // c == ')'
                if (open > 0) {
                    open--; // match with an existing '('
                } else {
                    close++; // no '(' available → extra ')'
                }
            }
        }
        
        // Total unmatched '(' + unmatched ')'
        return open + close;
    }
};
