class Solution {
  public:
    vector<int> result;

    int countLeaves(Node* node, int k) {
        if (!node) return 0;

        // If it's a leaf node
        if (!node->left && !node->right)
            return 1;

        int leftLeaves = countLeaves(node->left, k);
        int rightLeaves = countLeaves(node->right, k);

        int totalLeaves = leftLeaves + rightLeaves;

        // If this node has exactly k leaves in its subtree, collect it
        if (totalLeaves == k)
            result.push_back(node->data);

        return totalLeaves;
    }

    vector<int> btWithKleaves(Node *ptr, int k) {
        result.clear(); // reset result for each test case
        countLeaves(ptr, k);

        if (result.empty())
            return {-1};
        return result;
    }
};
