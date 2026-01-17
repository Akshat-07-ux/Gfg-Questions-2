class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for (char ch : s) {
            // Push everything except closing bracket
            if (ch != ')') {
                st.push(ch);
            } else {
                bool hasOperator = false;

                // Check contents inside the brackets
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                    st.pop();
                }

                // Pop the opening '('
                if (!st.empty()) st.pop();

                // No operator means redundant brackets
                if (!hasOperator) return true;
            }
        }

        return false;
    }
};
