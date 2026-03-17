class Solution {
  public:
    // Helper function to map parents and find the target node pointer
    Node* mapParents(Node* root, int target, unordered_map<Node*, Node*>& parent_map) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->data == target) targetNode = current;
            
            if (current->left) {
                parent_map[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_map[current->right] = current;
                q.push(current->right);
            }
        }
        return targetNode;
    }

    int minTime(Node* root, int target) {
        if (!root) return 0;

        unordered_map<Node*, Node*> parent_map;
        Node* targetNode = mapParents(root, target, parent_map);
        
        // BFS to spread the fire
        queue<Node*> q;
        q.push(targetNode);
        
        unordered_map<Node*, bool> visited;
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool burnedAny = false;
            
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                // Check Left Child
                if (current->left && !visited[current->left]) {
                    burnedAny = true;
                    visited[current->left] = true;
                    q.push(current->left);
                }
                // Check Right Child
                if (current->right && !visited[current->right]) {
                    burnedAny = true;
                    visited[current->right] = true;
                    q.push(current->right);
                }
                // Check Parent
                if (parent_map[current] && !visited[parent_map[current]]) {
                    burnedAny = true;
                    visited[parent_map[current]] = true;
                    q.push(parent_map[current]);
                }
            }
            // Only increment time if at least one new node was set on fire
            if (burnedAny) time++;
        }
        
        return time;
    }
};