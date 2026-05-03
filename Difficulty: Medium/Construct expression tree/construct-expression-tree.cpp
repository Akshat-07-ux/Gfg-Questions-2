/*
class Node
{
    public:
    char value;
    Node* left, *right;

    Node(char x){
        value = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* constructTree(string& postfix) {
        // Stack to store pointers to the nodes (subtrees)
        stack<Node*> st;

        for (char c : postfix) {
            // Check if the character is an operator
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                Node* newNode = new Node(c);

                // The first node popped is the right child
                // The second node popped is the left child
                if (!st.empty()) {
                    newNode->right = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    newNode->left = st.top();
                    st.pop();
                }

                // Push the combined subtree back to the stack
                st.push(newNode);
            } 
            else {
                // Character is an operand, create a leaf node and push it
                st.push(new Node(c));
            }
        }

        // The final element in the stack is the root of the tree
        return st.top();
    }
};