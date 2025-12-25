class Solution {
public:
    void dfs(Node* root, int level, int depth, int &ans) {
        if (!root) return;

        // Check if leaf node
        if (!root->left && !root->right) {
            if (level % 2 == 1) {
                ans = max(ans, depth);
            }
            return;
        }

        dfs(root->left, level + 1, depth + 1, ans);
        dfs(root->right, level + 1, depth + 1, ans);
    }

    int depthOfOddLeaf(Node *root) {
        int ans = 0;
        dfs(root, 1, 1, ans);
        return ans;
    }
};
