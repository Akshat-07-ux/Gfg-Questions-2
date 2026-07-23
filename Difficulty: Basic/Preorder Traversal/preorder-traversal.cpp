/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void traverse(Node* curr, vector<int>& result) {
        if (curr == nullptr) {
            return;
        }
        
        // 1. Visit Root
        result.push_back(curr->data);
        
        // 2. Traverse Left Subtree
        traverse(curr->left, result);
        
        // 3. Traverse Right Subtree
        traverse(curr->right, result);
    }

  public:
    vector<int> preOrder(Node* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};