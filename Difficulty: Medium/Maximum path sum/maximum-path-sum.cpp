class Solution {
  public:
    int maxPathSumUtil(Node* root, int &res) {
        if (root == NULL)
            return 0;

        // Recur for left and right subtrees
        int left = maxPathSumUtil(root->left, res);
        int right = maxPathSumUtil(root->right, res);

        // Max path for parent call of root. Either include left or right or none.
        int max_single = max(max(left, right) + root->data, root->data);

        // Max Top represents the sum when the node is the root of the max path
        int max_top = max(max_single, left + right + root->data);

        // Update the result (maximum found so far)
        res = max(res, max_top);

        return max_single;
    }

    int findMaxSum(Node *root) {
        int res = INT_MIN;
        maxPathSumUtil(root, res);
        return res;
    }
};
