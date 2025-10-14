class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if (root == NULL)
            return 0;

        // If current node is smaller than l, ignore left subtree
        if (root->data < l)
            return nodeSum(root->right, l, r);

        // If current node is greater than r, ignore right subtree
        if (root->data > r)
            return nodeSum(root->left, l, r);

        // Current node is in range, include it and search both sides
        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
    }
};
