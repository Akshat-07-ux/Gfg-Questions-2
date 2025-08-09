class Solution {
  public:
    int sum = 0; // running sum of greater values
    
    void transformTreeUtil(struct Node* root) {
        if (!root) return;
        
        // Process right subtree first (greater values)
        transformTreeUtil(root->right);
        
        // Save original value
        int original = root->data;
        
        // Replace with sum of greater nodes
        root->data = sum;
        
        // Update running sum
        sum += original;
        
        // Process left subtree
        transformTreeUtil(root->left);
    }
    
    void transformTree(struct Node *root) {
        sum = 0; // reset before transformation
        transformTreeUtil(root);
    }
};
