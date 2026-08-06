#include <string>
#include <stack>
#include <cctype>

class Solution {
  public:
    string preToInfix(string &s) {
        std::stack<std::string> st;

        // Traverse the string from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s[i];

            // If the character is an operand (letter), push it to stack
            if (std::isalpha(ch)) {
                st.push(std::string(1, ch));
            } 
            // If the character is an operator
            else {
                // Pop top two operands from stack
                std::string op1 = st.top(); st.pop();
                std::string op2 = st.top(); st.pop();

                // Form the infix string and push back to stack
                std::string infix = "(" + op1 + ch + op2 + ")";
                st.push(infix);
            }
        }

        // The top of the stack contains the result
        return st.top();
    }
};