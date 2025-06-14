/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isPerfect(Node *root) {
        if (root == NULL) {
            return true; // Empty tree is considered perfect
        }
        
        // Find the depth of the tree (depth of leftmost leaf)
        int depth = findDepth(root);
        
        // Check if all leaves are at the same depth and all internal nodes have two children
        return checkPerfect(root, depth, 0);
    }
    
private:
    // Helper function to find depth of the tree
    int findDepth(Node* node) {
        int depth = 0;
        while (node != NULL) {
            depth++;
            node = node->left;
        }
        return depth;
    }
    
    // Helper function to check if tree is perfect
    bool checkPerfect(Node* node, int depth, int level) {
        // Base case: if node is NULL
        if (node == NULL) {
            return true;
        }
        
        // If it's a leaf node
        if (node->left == NULL && node->right == NULL) {
            // Check if leaf is at the expected depth
            return (depth == level + 1);
        }
        
        // If it's an internal node, it must have both children
        if (node->left == NULL || node->right == NULL) {
            return false;
        }
        
        // Recursively check left and right subtrees
        return checkPerfect(node->left, depth, level + 1) && 
               checkPerfect(node->right, depth, level + 1);
    }
};