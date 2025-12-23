class Solution {
  public:
    void collectLeaves(Node* root, vector<Node*>& leaves) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            leaves.push_back(root);
            return;
        }
        
        collectLeaves(root->left, leaves);
        collectLeaves(root->right, leaves);
    }
    
    void pairwiseSwap(Node *root) {
        if (!root) return;
        
        vector<Node*> leaves;
        collectLeaves(root, leaves);
        
        // Swap leaf nodes pairwise
        for (int i = 0; i + 1 < leaves.size(); i += 2) {
            swap(leaves[i]->data, leaves[i + 1]->data);
        }
    }
};
