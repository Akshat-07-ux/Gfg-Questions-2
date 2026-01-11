class Solution {
  public:
    Node* prev = NULL;
    Node* head = NULL;

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        // Process current node
        if (prev == NULL) {
            head = root;   // first (smallest) node
        } else {
            prev->right = root;
        }

        root->left = NULL; // flattening rule
        prev = root;

        inorder(root->right);
    }

    Node* flattenBST(Node* root) {
        inorder(root);
        return head;
    }
};
