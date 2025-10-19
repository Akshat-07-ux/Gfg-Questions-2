/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->data);
        inorder(root->right, vals);
    }
    
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> vals;
        inorder(root, vals);

        // Custom sort: by absolute difference, then by smaller value
        sort(vals.begin(), vals.end(), [&](int a, int b) {
            int da = abs(a - target);
            int db = abs(b - target);
            if (da == db) return a < b;
            return da < db;
        });

        // Take first k elements
        vector<int> ans;
        for (int i = 0; i < k && i < (int)vals.size(); i++) {
            ans.push_back(vals[i]);
        }

        return ans;
    }
};
