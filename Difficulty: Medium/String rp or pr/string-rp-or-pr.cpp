// User function Template for C++
class Solution {
  public:
    long long solve(int X, int Y, string S) {
        // Decide the order based on which gives more value
        if (X > Y) {
            return removePattern(S, 'p', 'r', X, Y);
        } else {
            return removePattern(S, 'r', 'p', Y, X);
        }
    }
    
    long long removePattern(string& S, char ch1, char ch2, int val1, int val2) {
        stack<char> st;
        long long total = 0;

        // First pass to remove more valuable pattern: ch1 + ch2
        string temp;
        for (char c : S) {
            if (!st.empty() && st.top() == ch1 && c == ch2) {
                st.pop();
                total += val1;
            } else {
                st.push(c);
            }
        }

        // Rebuild the remaining string after first removal
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        // Second pass to remove the less valuable pattern: ch2 + ch1
        for (char c : temp) {
            if (!st.empty() && st.top() == ch2 && c == ch1) {
                st.pop();
                total += val2;
            } else {
                st.push(c);
            }
        }

        return total;
    }
};
