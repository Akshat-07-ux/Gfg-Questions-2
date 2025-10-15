/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        if (!root) return -1;
        
        std::stack<Node*> st;
        Node* curr = root;
        int count = 0;
        
        while (curr != NULL || !st.empty()) {
            // Go to the leftmost node
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            count++;
            
            // When count == k, we've found our answer
            if (count == k)
                return curr->data;
            
            // Move to the right subtree
            curr = curr->right;
        }
        
        // If k is greater than the number of nodes
        return -1;
    }
};
