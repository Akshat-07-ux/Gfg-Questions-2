#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        for (auto &s : arr) {
            // If it's a number
            if (!(s == "+" || s == "-" || s == "*" || s == "/" || s == "^")) {
                st.push(stoll(s));
            } else {
                // Operator: pop top 2
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;
                
                if (s == "+") res = a + b;
                else if (s == "-") res = a - b;
                else if (s == "*") res = a * b;
                else if (s == "/") {
                    // Need floor division
                    if ((a ^ b) < 0 && a % b != 0) 
                        res = (a / b) - 1;
                    else 
                        res = a / b;
                }
                else if (s == "^") {
                    res = pow(a, b); // guaranteed to fit in 32-bit int
                }
                st.push(res);
            }
        }
        return (int)st.top();
    }
};
