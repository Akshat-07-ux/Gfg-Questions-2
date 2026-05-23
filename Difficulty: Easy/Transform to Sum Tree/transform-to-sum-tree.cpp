/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  private:
    // Helper function that returns the total sum of the subtree 
    // rooted at 'root' before it gets modified.
    int calculateSumTree(Node* root) {
        // Base case: An empty tree contributes 0 to the sum
        if (root == nullptr) {
            return 0;
        }

        // Save the old value of the current node before we overwrite it
        int old_val = root->data;

        // Recursively compute the sums of left and right subtrees
        int left_sum = calculateSumTree(root->left);
        int right_sum = calculateSumTree(root->right);

        // Update current node's data to be the sum of its subtrees
        root->data = left_sum + right_sum;

        // Return the total sum of this subtree to the parent.
        // Total sum = old value of this node + total sum of its subtrees.
        return old_val + root->data;
    }

  public:
    void toSumTree(Node *root) {
        // Initiate the recursive transformation
        calculateSumTree(root);
    }
};