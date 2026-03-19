/* Tree node structure used in the program
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct NodeInfo {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

class Solution {
  public:
    NodeInfo solve(Node* root, int &maxSize) {
        // Base case: An empty tree is a BST of size 0
        if (root == NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Post-order traversal: Get info from children first
        NodeInfo left = solve(root->left, maxSize);
        NodeInfo right = solve(root->right, maxSize);

        NodeInfo current;
        current.size = left.size + right.size + 1;

        // Check BST properties:
        // 1. Left and Right subtrees must be BSTs
        // 2. Current node data must be > max of left subtree
        // 3. Current node data must be < min of right subtree
        if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal) {
            current.isBST = true;
            current.minVal = min(root->data, left.minVal);
            current.maxVal = max(root->data, right.maxVal);
            
            // Update the global maximum size found so far
            maxSize = max(maxSize, current.size);
        } else {
            current.isBST = false;
            // Values below don't strictly matter for non-BSTs, 
            // but we keep size for the return structure
        }

        return current;
    }

    int largestBst(Node *root) {
        int maxSize = 0;
        solve(root, maxSize);
        return maxSize;
    }
};