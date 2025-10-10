#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);

            for (int i = 0; i < n; i++) {
                Node* node = q.front(); q.pop();

                // Decide index based on direction
                int index = leftToRight ? i : (n - 1 - i);
                level[index] = node->data;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Append level to result
            result.insert(result.end(), level.begin(), level.end());
            leftToRight = !leftToRight; // flip direction
        }

        return result;
    }
};
