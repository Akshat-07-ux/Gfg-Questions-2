/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  private:
    int dfs(Node* node, int &max_diff) {
        if (!node) return INT_MAX;

        // Leaf nodes have no descendants
        if (!node->left && !node->right) return node->data;

        // Find the minimum value in left and right subtrees
        int left_min = dfs(node->left, max_diff);
        int right_min = dfs(node->right, max_diff);

        int min_descendant = std::min(left_min, right_min);

        // Update maximum difference (Ancestor value - Descendant value)
        max_diff = std::max(max_diff, node->data - min_descendant);

        // Return the minimum value in the subtree rooted at this node
        return std::min(node->data, min_descendant);
    }

  public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        dfs(root, max_diff);
        return max_diff;
    }
};