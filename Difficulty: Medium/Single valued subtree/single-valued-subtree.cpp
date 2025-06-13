// User function Template for C++

/* Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
  private:
    int count = 0;

    bool isSingleValued(Node* root) {
        if (!root) return true;

        // Recursively check left and right subtrees
        bool left = isSingleValued(root->left);
        bool right = isSingleValued(root->right);

        // If either subtree is not single-valued, this can't be
        if (!left || !right)
            return false;

        // Check if left child exists and differs in value
        if (root->left && root->left->data != root->data)
            return false;

        // Check if right child exists and differs in value
        if (root->right && root->right->data != root->data)
            return false;

        // Current node is root of a single-valued subtree
        count++;
        return true;
    }

  public:
    int singlevalued(Node *root) {
        count = 0;
        isSingleValued(root);
        return count;
    }
};
