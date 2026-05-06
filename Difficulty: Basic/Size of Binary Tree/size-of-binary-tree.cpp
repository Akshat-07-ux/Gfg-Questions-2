/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* root) {
        // Base Case: If the tree is empty, size is 0
        if (root == NULL) {
            return 0;
        }
        
        // Recursive Call: 1 (current node) + size of left + size of right
        return 1 + getSize(root->left) + getSize(root->right);
    }
};