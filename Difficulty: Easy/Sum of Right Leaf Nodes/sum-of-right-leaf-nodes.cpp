/* Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/

// function should return the sum of all right leaf nodes
class Solution {
  public:
    int rightLeafSum(Node* root) {
        return dfs(root, false); // false means root is not a right child
    }

  private:
    int dfs(Node* node, bool isRightChild) {
        if (node == nullptr) return 0;

        // Check if this node is a leaf
        if (node->left == nullptr && node->right == nullptr) {
            return isRightChild ? node->data : 0;
        }

        // Recurse for left and right children
        int leftSum = dfs(node->left, false);
        int rightSum = dfs(node->right, true);

        return leftSum + rightSum;
    }
};
