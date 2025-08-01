/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    // Helper function to reverse nodes at alternate levels
    void reverseAlternateUtil(Node* left, Node* right, bool level) {
        if (!left || !right) return;

        // If level is odd, swap data
        if (level)
            std::swap(left->data, right->data);

        // Recur for left subtree of left and right subtree of right
        reverseAlternateUtil(left->left, right->right, !level);
        reverseAlternateUtil(left->right, right->left, !level);
    }

    void reverseAlternate(Node *root) {
        if (!root) return;
        reverseAlternateUtil(root->left, root->right, true);
    }
};
