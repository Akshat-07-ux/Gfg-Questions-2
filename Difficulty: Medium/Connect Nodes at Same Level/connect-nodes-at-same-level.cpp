/* struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};*/

class Solution {
   public:
    void connect(Node *root) {
        if (!root) return;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();
                q.pop();
                
                // Connect to next node in the same level
                // If it's the last node in level, nextRight remains NULL
                if (i < levelSize - 1) {
                    curr->nextRight = q.front();
                } else {
                    curr->nextRight = NULL;
                }
                
                // Add children to queue for next level
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }
};
