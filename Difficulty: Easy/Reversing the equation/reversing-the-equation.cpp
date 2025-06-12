class Solution {
    public:
    string reverseEqn(string s) {
        stack<string> stk;
        int n = s.size();
        string num = "";

        for (int i = 0; i < n; ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num += ch;  // collect full number
            } else {
                // push the complete number collected
                if (!num.empty()) {
                    stk.push(num);
                    num = "";
                }
                string op(1, ch);
                stk.push(op); // push operator
            }
        }

        // push last number if any
        if (!num.empty()) {
            stk.push(num);
        }

        // Build reversed equation
        string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};
