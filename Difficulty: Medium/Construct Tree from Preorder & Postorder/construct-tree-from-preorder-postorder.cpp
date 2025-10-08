/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int preIndex = 0;  // Tracks current index in preorder traversal

    Node* constructTreeUtil(vector<int>& pre, vector<int>& post, int l, int h, int size) {
        if (preIndex >= size || l > h)
            return nullptr;

        // Create root node
        Node* root = new Node(pre[preIndex++]);

        // If only one node, no need to look further
        if (l == h || preIndex >= size)
            return root;

        // Find the next preorder element in postorder to determine left subtree size
        int i;
        for (i = l; i <= h; i++) {
            if (post[i] == pre[preIndex])
                break;
        }

        // Build left and right subtrees recursively
        if (i <= h) {
            root->left = constructTreeUtil(pre, post, l, i, size);
            root->right = constructTreeUtil(pre, post, i + 1, h - 1, size);
        }

        return root;
    }

    Node* constructTree(vector<int>& pre, vector<int>& post) {
        int size = pre.size();
        preIndex = 0;
        return constructTreeUtil(pre, post, 0, size - 1, size);
    }
};
