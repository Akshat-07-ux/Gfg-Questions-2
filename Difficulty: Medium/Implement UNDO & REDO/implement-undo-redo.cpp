class Solution {
  private:
    stack<char> st;      // Stores current document content
    stack<char> redoSt;  // Stores characters removed by undo

  public:
    void append(char x) {
        st.push(x);
        // Once a new character is appended, the redo history is cleared
        while (!redoSt.empty()) {
            redoSt.pop();
        }
    }

    void undo() {
        if (!st.empty()) {
            char val = st.top();
            st.pop();
            redoSt.push(val);
        }
    }

    void redo() {
        if (!redoSt.empty()) {
            char val = redoSt.top();
            redoSt.pop();
            st.push(val);
        }
    }

    string read() {
        string res = "";
        stack<char> temp = st;
        // Since stack is LIFO, we need to reverse the characters
        while (!temp.empty()) {
            res += temp.top();
            temp.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};