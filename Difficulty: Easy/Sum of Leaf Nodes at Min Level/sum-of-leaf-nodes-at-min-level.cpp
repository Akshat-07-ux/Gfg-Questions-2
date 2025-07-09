#include <queue>

class Solution {
  public:
    int minLeafSum(Node *root) {
        if (!root) return 0;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int levelLeafSum = 0;
            bool foundLeaf = false;

            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();

                // If it's a leaf node, add to the level sum
                if (!curr->left && !curr->right) {
                    levelLeafSum += curr->data;
                    foundLeaf = true;
                } else {
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
            }

            // If leaf was found at this level, return the sum
            if (foundLeaf) return levelLeafSum;
        }

        return 0; // Should not reach here if tree is non-empty
    }
};
