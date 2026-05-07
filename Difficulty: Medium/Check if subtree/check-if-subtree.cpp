/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Helper function to check if two trees are identical
    bool isIdentical(Node* r1, Node* r2) {
        // If both are null, they are identical
        if (!r1 && !r2) return true;
        
        // If one is null or data doesn't match, they aren't identical
        if (!r1 || !r2 || r1->data != r2->data) return false;
        
        // Recursively check left and right subtrees
        return isIdentical(r1->left, r2->left) && 
               isIdentical(r1->right, r2->right);
    }

    bool isSubTree(Node* root1, Node* root2) {
        // If S is empty, it's technically a subtree of any tree
        if (!root2) return true;
        
        // If T is empty but S is not, S cannot be a subtree
        if (!root1) return false;

        // If the current nodes match, check if the trees are identical
        if (root1->data == root2->data) {
            if (isIdentical(root1, root2)) return true;
        }

        // Search in the left and right children of root1
        return isSubTree(root1->left, root2) || 
               isSubTree(root1->right, root2);
    }
};