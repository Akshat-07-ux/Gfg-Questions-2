// NEW POTD Submission
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
        
       
        result.push_back(curr->data);
        
        
        traverse(curr->left, result);
        
        
        traverse(curr->right, result);
    }

  public:
    vector<int> preOrder(Node* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};