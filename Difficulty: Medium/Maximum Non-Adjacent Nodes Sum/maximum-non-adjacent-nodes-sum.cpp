/*
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
  public:
    pair<int, int> solve(Node* root) {
        if (!root) return {0, 0};
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // If we include this node, we cannot include its children
        int include = root->data + left.second + right.second;
        
        // If we exclude this node, we can take max of including or excluding children
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }
    
    int getMaxSum(Node *root) {
        auto res = solve(root);
        return max(res.first, res.second);
    }
};
