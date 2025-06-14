/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
 public:
    bool isMirror(Node* left, Node* right) {
        // If both nodes are null, they are mirrors
        if (!left && !right) return true;
        
        // If only one of them is null, they are not mirrors
        if (!left || !right) return false;
        
        // Check if current nodes are equal and their subtrees are mirrors
        return (left->data == right->data) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(Node* root) {
        if (!root) return true;  // Empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};