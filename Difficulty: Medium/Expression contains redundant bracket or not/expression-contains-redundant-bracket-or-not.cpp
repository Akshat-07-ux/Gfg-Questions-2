class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                bool operatorFound = false;

                // Pop elements till '(' and check for operator in between
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        operatorFound = true;
                    }
                }

                if (!st.empty()) st.pop(); // pop the opening '('

                if (!operatorFound) {
                    return 1; // redundant parenthesis found
                }
            } else {
                st.push(ch);
            }
        }

        return 0; // no redundancy found
    }
};
