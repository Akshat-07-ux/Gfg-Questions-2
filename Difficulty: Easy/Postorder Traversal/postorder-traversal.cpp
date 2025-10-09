class Solution {
  public:
    void postOrderTraversal(Node* root, vector<int>& result) {
        if (root == NULL) return;
        
        // 1️⃣ Visit left subtree
        postOrderTraversal(root->left, result);
        // 2️⃣ Visit right subtree
        postOrderTraversal(root->right, result);
        // 3️⃣ Visit node itself
        result.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        vector<int> result;
        postOrderTraversal(root, result);
        return result;
    }
};
