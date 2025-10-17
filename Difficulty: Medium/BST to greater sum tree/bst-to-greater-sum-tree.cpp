/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int sum = 0; // running sum of all nodes greater than current

    void transformTree(Node *root) {
        if (!root) return;

        // Traverse right subtree first (greater values)
        transformTree(root->right);

        // Store original node value
        int original = root->data;

        // Replace node’s value with current greater sum
        root->data = sum;

        // Update sum to include the original value
        sum += original;

        // Traverse left subtree (smaller values)
        transformTree(root->left);
    }
};
